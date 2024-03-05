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
        cout << "Duplicate Node having data -> " << this -> data << " is deleted" << endl;
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

void removeDupicateNodes(Node* &head){
    if(head == NULL || head -> next == NULL)
        return;

    Node* temp = head;
    while(temp -> next != NULL){
        Node* prev = temp;
        Node* curr = temp -> next;
        while(curr != NULL){
            if(curr -> data == temp -> data){
                prev -> next = curr -> next;
                curr -> next = NULL;
                delete curr;
                curr = prev -> next;
            }
            else{
                prev = curr;
                curr = prev -> next;
            }
        }
        if(temp -> next != NULL){
            temp = temp -> next;
        }
    }    
}



int main(){
    Node* head = NULL;

    insertNode(head,3,1);
    insertNode(head,5,1);
    insertNode(head,7,3);
    insertNode(head,10,2);
    insertNode(head,1,5);
    insertNode(head,1,3);
    insertNode(head,7,7);

    printLL(head);

    removeDupicateNodes(head);
    printLL(head);

}