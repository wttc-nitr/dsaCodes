/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define Ft first
#define Sd second

class Node {
public:
    int data;
    Node *next;
};

void printList(Node *head){
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
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


    return 0;
}