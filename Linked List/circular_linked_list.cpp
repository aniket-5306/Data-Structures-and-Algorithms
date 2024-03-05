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

void nodeInsertionAtPosition(Node* &head,Node* &tail, int data, int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail -> next = head;
        return;
    }
    if(position == 1){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        tail -> next = head;
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == head){
        Node* newNode = new Node(data);
        temp -> next = newNode;
        tail = newNode;
        tail -> next = head;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void printCLL(Node* &head){
    Node* ptr = head;
    while(ptr -> next != head){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
    cout << endl;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    nodeInsertionAtPosition(head,tail,7,5);
    printCLL(head);

    nodeInsertionAtPosition(head,tail,6,1);
    printCLL(head);

    nodeInsertionAtPosition(head,tail,55,3);
    printCLL(head);

    nodeInsertionAtPosition(head,tail,70,2);
    printCLL(head);


}