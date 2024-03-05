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

void insertNode(Node* &head, int data, int position){
    //node insertion when linked list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    //node insertion from begining
    if(position == 1){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //node insertion from last
    if(temp -> next == NULL){
        Node* newNode = new Node(data);
        temp -> next = newNode;
        return;
    }
    //node insertion inbetween
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void printLL(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

Node* reverseInK(Node* head, int k){

    if(head == NULL || head -> next == NULL)
        return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int cnt = 0;
    while(curr != NULL && cnt < k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }  
    if(forward != NULL){
        head -> next = reverseInK(forward,k);
    }  
    return prev;
}

int main(){

    Node* head = NULL;

    insertNode(head,2,1);
    insertNode(head,1,1);
    insertNode(head,4,3);
    insertNode(head,3,3);
    insertNode(head,6,5);
    insertNode(head,5,5);
    insertNode(head,7,7);

    printLL(head);

    head = reverseInK(head,3);

    printLL(head);

}