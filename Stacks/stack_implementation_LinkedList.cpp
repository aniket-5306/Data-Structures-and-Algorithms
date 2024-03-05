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
        cout << this -> data << " is popped out!" << endl;
    }
};

void push(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
    cout << newNode -> data << " is pushed into the stack!" << endl;
}

void pop(Node* &head){
    if(head == NULL){
        cout << "Stack is Underflow!" << endl;
        return;
    }

    Node* temp = head;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
}

void peak(Node* head){
    if(head == NULL){
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << head -> data << endl;
}

bool isEmpty(Node* head){
    if(head == NULL)
        return true;
    return false;    
}

void printStack(Node* head){
    if(head == NULL){
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;

    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);

    printStack(head);
    peak(head);


    pop(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);

    peak(head);

    pop(head);

    cout << isEmpty(head) << endl;
    

}