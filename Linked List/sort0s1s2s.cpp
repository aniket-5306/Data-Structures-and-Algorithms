#include<bits/stdc++.h>
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

void insertNode(Node* &head, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(data);
    temp -> next = newNode;
}

void printLL(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

vector<int> countZerosOnesTwos(Node* head){
    vector<int> count0s1s2s(3,0);
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)
            count0s1s2s[0]++;
        else if(temp -> data == 1)
            count0s1s2s[1]++;
        else
            count0s1s2s[2]++;   
        temp = temp -> next;    
    }
    return count0s1s2s;
}



int main(){

    Node* head = NULL;

    insertNode(head,2);
    insertNode(head,0);
    insertNode(head,1);
    insertNode(head,0);
    insertNode(head,2);
    insertNode(head,1);
    insertNode(head,2);

    printLL(head);

    vector<int> count0s1s2s = countZerosOnesTwos(head);
    Node* temp = head;

    for(int i = 0; i < count0s1s2s.size(); i++){
        int count = count0s1s2s[i];
        while(count != 0 && temp != NULL){
            temp -> data = i;
            temp = temp -> next;
            count--;
        }
    }

    cout << "Sorted Linked List : ";
    printLL(head);

}