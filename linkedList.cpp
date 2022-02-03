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
    while (head->next){  // not "while (head)"
        head = head->next;
    }

    Node *new_node = new Node();
    new_node->data = data;

    new_node->next = NULL;

    head->next = new_node;
}

Node *Reverse(Node *head){
    Node *prev = NULL, *curr = head, *frwd = NULL;
    
    while (curr){
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    
    return prev;
}

void initList(Node **head_ref, int n){
    int k; cout << "enter num :\n" << endl;
    cin >> k;

    push(head_ref, k);

    while (--n > 0){
        cout << "enter num :\n" << endl;
        cin >> k;

        append(*head_ref, k);
    }
}

Node *merge(Node* A, Node *B){
    // if one list is empty, return the other
    if (A == NULL)
        return B;
    
    if (B == NULL)
        return A;
        
    Node *i = A, *j = B; 
    Node *head = NULL;
    
    // deciding the first node in the merged list
    if (i->data <= j->data){
        head = i;
        i = i->next;
    }
    else {
        head = j;
        j = j->next;
    }

    // merging operation, just changing the Next of one node to point to one of the two available nodes
    while (i && j){
        if (i->data <= j->data){
            head->next = i;
            i = i->next;
        }
        else {
            head->next = j;
            j = j->next;
        }

        head = head->next;
    }

    // merge the unfinished list
    if (i)
        head->next = i;

    if (j)
        head->next = j;

    return A->data <= B->data ? A : B;

}

int main(void){
     ios::sync_with_stdio(0); //cin.tie(0);
     
    // Node *head = NULL;
    // Node *second = NULL;
    // Node *third = NULL;

    // head = new Node();
    // second = new Node();
    // third = new Node();

    // head->data = 1;
    // head->next = second;

    // second->data = 2;
    // second->next = third;

    // third->data = 3;
    // third->next = NULL; 

    // printList(head);
    
    // printList(Reverse(head));

    Node *list = NULL;

    initList(&list, 5);

    printList(list);

    return 0;
}