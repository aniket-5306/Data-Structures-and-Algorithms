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

//recursive way to reverse linked list
void reverseLL(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverseLL(head, forward, curr);
    curr -> next = prev;
}

//function to reverse a linked list
void reverseLinkedList(Node* &head){

    // recursive approach
    if(head == NULL || head -> next == NULL)
        return;

    Node* curr = head;
    Node* prev = NULL;

    reverseLL(head, curr, prev);

    /*
    //iterative approach
    if(head == NULL || head -> next == NULL)
        return;

    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){ 
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    */
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

    reverseLinkedList(head);
    printLL(head);
}