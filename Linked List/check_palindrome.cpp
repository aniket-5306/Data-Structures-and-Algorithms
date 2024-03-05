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


void nodeInsertion(Node* &head, int data, int position){
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

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int findMid(Node* head){
    int size = 0;
    Node* temp = head;
    while(temp != NULL){
        size++;
        temp = temp -> next;
    }
    int mid = -1;
    if(size % 2 == 0){
        mid = size / 2;
    }
    else{
        mid = size / 2 + 1;
    }
    return mid;
}

void reverseLL(Node* head){
    if(head -> next == NULL)
        return;  

    Node* curr = head -> next;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL)   {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head -> next = prev;
}

bool checkPalindrome(Node* head){
    if(head == NULL || head -> next == NULL)
        return true;

    int mid = findMid(head);
    int cnt = 1;
    Node* midtemp = head;
    while(cnt < mid){
        midtemp = midtemp -> next;
        cnt++;
    }

    reverseLL(midtemp);

    Node* ftemp = head;
    Node* stemp = midtemp -> next; 
    
    while(ftemp != midtemp -> next && stemp != NULL){
        if(ftemp -> data != stemp -> data){
            return false;
        }
        ftemp = ftemp -> next;
        stemp = stemp -> next;
    }

    reverseLL(midtemp);

    return true;

}


int main(){

    Node* head = NULL;
    
    nodeInsertion(head,7,1);
    nodeInsertion(head,5,1);
    nodeInsertion(head,3,3);
    nodeInsertion(head,5,4);
    nodeInsertion(head,7,4);
    // nodeInsertion(head,3,4);

    printLL(head);

    if(checkPalindrome(head))
        cout << "Given linked list is a palindrome." << endl;
    else    
        cout << "Not a palindrome." << endl;    

    printLL(head);

}