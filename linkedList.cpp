#include "bits/stdc++.h"
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void printList(Node *head){
    cout << "the list is: \n";

    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }

    cout << "\n\n";
}

void printList_dotOperator(Node *head){
    while (head){
        cout << (*head).data << ' ';
        head = (*head).next;
    }
}

// delete first node via returning new head 
Node *deleteFirst_ReturnHead(Node *Head){
    // if list is empty
    if (Head == NULL)
        return Head;

    Node *temp = Head;

    Head = Head->next;

    free(temp);

    return Head;
}

// if you want to modify the local variable of one function inside another function, pass a pointer to that variable
// So, we are changing the value of head here.
void deleteFirst(Node **head_ref){
    if (*head_ref == NULL)
        return;

    Node *temp = *head_ref;

    *head_ref = (*head_ref)->next;

    free(temp);
}

// insert at beginning
void push(Node **head_ref, int data){
    Node *new_node = new Node();

    new_node->data = data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

// insert after a given node
void insertAfter(Node *prev, int data){
    if (prev == NULL){
        cout << "previous node can't be null.\n"; return;
    }

    Node *new_node = new Node();
    
    new_node->data = data;

    new_node->next = prev->next;

    prev->next = new_node;
}

void append(Node *head, int data){
    while (head->next){
        head = head->next;
    }

    Node *new_node = new Node();
    new_node->data = data;

    new_node->next = NULL;

    head->next = new_node;
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
     
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; 

    printList(head);
       
    append(head, 9);

    printList(head);

    return 0;
}