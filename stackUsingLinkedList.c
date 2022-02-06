#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *next;
};

typedef struct Node Node;

void printList(Node *head){
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}

Node *head = NULL;

bool isEmpty(void){
    if (!head)
        return true;
    return false;
}

void Push(int x){
    Node *new_node = (Node*)malloc(sizeof(int));
    new_node->val = x;
    new_node->next = head;
    head = new_node;
}

void Pop(void){
    if (isEmpty()){
        printf("stack is already empty.\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}

int Top(void){
    if (isEmpty())
        return -1;

    return head->val;
}

int main(void){
    for (int i=1; i <= 10; i++)
        Push(i);

    printList(head);

    for (int cnt = 1; cnt <= 5; cnt++) {
        printf("top element is %d.\n", Top());
        Pop();
    }

    printf("top element is %d\n", Top());

    return 0;
}
