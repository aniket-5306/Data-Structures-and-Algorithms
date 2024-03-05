#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        cout << "Node is deleted having value -> " << value << endl;
    }
};

int len(Node* &head){
    Node* ptr = head;
    int length = 0;
    while(ptr != NULL){
        length++;
        ptr = ptr -> next;
    }
    return length;
}

void insertNode(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtEnd(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){

    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        return;
    }

    int size = len(head);
    if(position > size){
        Node* newNode = new Node(data);
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    Node* previous = NULL;
    Node* current = head;
    int cnt = 1;
    while(cnt < position){
        previous = current;
        current = current -> next;
        cnt++;
    }

    newNode -> next = previous -> next;
    current -> prev = newNode;
    previous -> next = newNode;
}

void deleteNode(Node* &head){
    if(head != NULL){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }
    else{
        cout << "Linked List is empty!" << endl;
    }
}

void deleteNodeAtPosition(Node* &head, Node* &tail, int position){

    if(head != NULL){

        if(position == 1){
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }

        Node* temp = head;
        int cnt = 1;
        while(cnt < position){
            temp = temp -> next;
            cnt++;
        }
        if(temp -> next == NULL){
            tail = temp -> prev;
            temp -> prev -> next = NULL;
            temp -> prev = NULL;
            delete temp;
            return;
        }

        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        temp -> prev = NULL;
        temp -> next = NULL;
        delete temp;

    }
    else{
        cout << "Linked List is empty!" << endl;
    }
    
}

void nodeRemovalByValue(Node* &head, Node* &tail, int value){
    if(head == NULL){
        cout << "Linked List is empty!" << endl;
        return;
    }

    if(head -> data == value){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    Node* temp = head -> next;
    while(temp != NULL){
        if(temp -> data == value){    
            if(temp -> next == NULL){
                tail = temp -> prev;
                temp -> prev -> next = NULL;
                temp -> prev = NULL;
                delete temp;
                return;
            }
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            temp -> next = NULL;
            temp -> prev = NULL;
            delete temp;
            return;
        }
        temp = temp -> next;
    }
    cout << "The node you want to delete is not present!" << endl;
}

void printDLL(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    // Node* node1 = new Node(7);

    insertNode(head, tail, 10);
    printDLL(head);

    insertNode(head, tail, 20);
    printDLL(head);

    insertNode(head, tail, 30);
    printDLL(head);

    insertNode(head, tail, 50);
    printDLL(head);

    cout << "first node -> " << head -> data << endl;
    cout << "last node -> " << tail -> data << endl;

    cout << "Length of list -> " << len(head) << endl;

    insertAtEnd(tail, head, 17);
    printDLL(head);

    insertAtPosition(head, tail, 99, 3);
    printDLL(head);

    insertAtPosition(head, tail, 109, 1);
    printDLL(head);

    insertAtPosition(head, tail, 999, 8);
    printDLL(head);

    cout << "first node -> " << head -> data << endl;
    cout << "last node -> " << tail -> data << endl;

    deleteNode(head);
    printDLL(head);

    deleteNodeAtPosition(head, tail, 2);
    printDLL(head);

    deleteNodeAtPosition(head, tail, 1);
    printDLL(head);

    deleteNodeAtPosition(head, tail, 5);
    printDLL(head);

    nodeRemovalByValue(head, tail, 17);
    printDLL(head);

    nodeRemovalByValue(head, tail, 99);
    printDLL(head);

    cout << "first node -> " << head -> data << endl;
    cout << "last node -> " << tail -> data << endl;

}