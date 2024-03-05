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
    ~Node(){
        cout << "Duplicate Node whose data -> " << this -> data << " is deleted" << endl;
    }
};

void insertNode(Node* &head, int data, int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    if(position == 1){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){
        Node* newNode = new Node(data);
        temp -> next = newNode;
        return;
    }
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

void removeDuplicates(Node* &head){
    if(head == NULL || head -> next == NULL)
        return;

    Node* curr = head;   
    Node* forward = curr -> next; 
    while(forward != NULL){
        if(forward -> data == curr -> data){
            curr -> next = forward -> next;
            forward -> next = NULL;
            delete forward;
            forward = curr -> next;
        }
        else{
            curr = forward;
            forward = curr -> next;
        }
    }
}



int main(){

    Node* head = NULL;

    insertNode(head,2,1);
    insertNode(head,1,1);
    insertNode(head,1,1);
    insertNode(head,3,4);
    insertNode(head,3,5);
    insertNode(head,3,6);
    insertNode(head,4,7);
    insertNode(head,5,8);
    insertNode(head,5,9);

    printLL(head);

    removeDuplicates(head);
    printLL(head);

}