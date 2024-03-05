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

void nodeInsertion(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertionFromEnd(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void insertionInBetween(Node* &head, Node* &tail, int data, int position){

    if(position == 1){
        nodeInsertion(head, data);
        return;
    }

    Node* prevNode = head;
    int i = 2;
    while(i < position){
        prevNode = prevNode -> next;
        i++;
    }

    if(prevNode -> next == NULL){
        insertionFromEnd(tail,data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = prevNode -> next;
    prevNode -> next = newNode;
}


void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

/*
    //creation of first node
    Node* node1 = new Node(121);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node* head = node1;
    printLinkedList(head);

    //insertion from begining
    nodeInsertion(head,10);
    printLinkedList(head);

    nodeInsertion(head,7);
    printLinkedList(head);
*/


    Node* fnode = new Node(15);
    Node* head = fnode;
    Node* tail = fnode;

    printLinkedList(head);

    //insertion from end
    insertionFromEnd(tail,25);
    printLinkedList(head);

    insertionFromEnd(tail,35);
    printLinkedList(head);

    insertionFromEnd(tail,45);
    printLinkedList(head);

    insertionFromEnd(tail,55);
    printLinkedList(head);

    //inertion in Between
    insertionInBetween(head,tail,40,4);
    printLinkedList(head);

    insertionInBetween(head,tail,50,6);
    printLinkedList(head);

    insertionInBetween(head,tail,10,1);
    printLinkedList(head);

    insertionInBetween(head,tail,60,9);
    printLinkedList(head);

    // cout << head -> data << endl;
    // cout << tail -> data << endl;

}