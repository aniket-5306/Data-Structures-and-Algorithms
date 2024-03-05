#include<iostream>
using namespace std;

#include <bits/stdc++.h>

    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

void insertNode(Node<int>* &head, int data){
    if(head == NULL){
        Node<int>* newNode = new Node(data);
        head = newNode;
        return;
    }

    Node<int>* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node<int>* newNode = new Node(data);
    temp -> next = newNode;
}

Node<int>* mergeTwoSortedList(Node<int>* first, Node<int>* second)
{
    Node<int>* head = NULL;

    Node<int>* ftemp = first;
    Node<int>* stemp = second;

    while(ftemp != NULL && stemp != NULL){
        if((ftemp -> data) <= (stemp -> data)){
            insertNode(head, (ftemp -> data));
            ftemp = ftemp -> next;
        }
        else{
            insertNode(head, stemp -> data);
            stemp = stemp -> next;
        }
    }

    while(ftemp != NULL){
        insertNode(head, ftemp -> data);
        ftemp = ftemp -> next;
    }

    while(stemp != NULL){
        insertNode(head, stemp -> data);
        stemp = stemp -> next;
    }

    return head;

}

void printLL(Node<int>* &head){
    Node<int>* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node<int>* fhead = NULL;
    Node<int>* shead = NULL;

    insertNode(fhead,5);
    printLL(fhead);

    insertNode(shead,1);
    insertNode(shead,3);
    insertNode(shead,6);
    insertNode(shead,10);
    printLL(shead);

    Node<int>* head = mergeTwoSortedList(fhead,shead);
    printLL(head);

}