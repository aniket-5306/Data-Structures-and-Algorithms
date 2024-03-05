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
        cout << "Node is deleted having data -> " << this -> data << endl;
    }
};

void insertNode(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = tail -> next;
}

void printLinkedList(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

void deleteNode(Node* &head, int position){
    if(head != NULL){
        if(position == 1){
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }
        else{
            Node* current = head;
            Node* prev = NULL;
            int cnt = 1;
            while(cnt < position){
                prev = current;
                current = current -> next;
                cnt++;
            }
            prev -> next = current -> next;
            current -> next = NULL;
            delete current;
        }
    }
    else{
        cout << "Linked List is empty!" << endl;
    }
}

void nodeRemoval(Node* &head, int data){
    if(head != NULL){
        if(head -> data == data){
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }
        else{
            Node* current = head;
            Node* prev = NULL;
            prev = current;
            current = current -> next;
            while(current != NULL){
                if(current -> data == data){
                    prev -> next = current -> next;
                    current -> next = NULL;
                    delete current;
                    return;
                }
                prev = current;
                current = current -> next;
            }
        }
        cout << "The node you want to delete is not found!" << endl;
    }
    else{
        cout << "Linked List is empty!" << endl;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    Node* node1 = new Node(100);

    head = node1;
    tail = node1;

    insertNode(tail,400);
    printLinkedList(head);

    insertNode(tail,800);
    printLinkedList(head);

    insertNode(tail,1600);
    printLinkedList(head);

    insertNode(tail,3200);
    printLinkedList(head);

    deleteNode(head, 4);
    printLinkedList(head);

    deleteNode(head, 1);
    printLinkedList(head);

    nodeRemoval(head, 800);
    printLinkedList(head);

    nodeRemoval(head, 200);
    printLinkedList(head);

    nodeRemoval(head, 400);
    printLinkedList(head);

    nodeRemoval(head, 3200);
    printLinkedList(head);

    nodeRemoval(head, 3200);
    printLinkedList(head);

    deleteNode(head, 1);
    printLinkedList(head);

}