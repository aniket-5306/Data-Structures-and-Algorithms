#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void printLL(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

int lengthLL(Node* &head){
    Node* ptr = head;
    int len = 0;
    while(ptr != NULL){
        len++;
        ptr = ptr -> next;
    }
    return len;
}

void nodeInsertionAtPosition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    
    if(position == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }

    Node* ptr = head;
    int cnt = 1;
    while(cnt < position-1){
        ptr = ptr -> next;
        cnt++;
    }
    if(ptr -> next == NULL){
        ptr -> next = newNode;
        return;
    }
    newNode -> next = ptr -> next;
    ptr -> next = newNode;
}

void middleOfLinkedList(Node* &head){
    if(head == NULL){
        cout << "Linked List is empty!" << endl;
        return;
    }

    int len = lengthLL(head);
    int mid = -1;
    if(len % 2 == 0)
        mid = len/2 + 1;
    else if(len % 2 == 1)
        mid = len/2 + 1;

    Node* temp = head;
    int cnt = 1;
    while(cnt < mid){
        temp = temp -> next;
        cnt++;
    }        
    cout << "Middle Element of Linked List -> " << temp -> data << endl;
}


int main(){
    Node* head = NULL;

    nodeInsertionAtPosition(head,10,1);
    printLL(head);

    nodeInsertionAtPosition(head,5,1);
    printLL(head);

    nodeInsertionAtPosition(head,20,3);
    printLL(head);

    nodeInsertionAtPosition(head,15,3);
    printLL(head);

    nodeInsertionAtPosition(head,7,2);
    printLL(head);

    middleOfLinkedList(head);

}