#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void pushBack(int data){
        if(rear > size - 1){
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    void popFront(){
        if(front == rear){
            cout << "Queue is empty!" << endl;
            front = 0;
            rear = 0;
            return;
        }
        if(front == rear - 1){
            front = 0;
            rear = 0;
            return;
        }
        arr[front] = 0;
        front++;
    }

    int peakFront(){
        if(front == rear){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    int peakBack(){
        if(front == rear){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear-1];
    }

    bool isEmpty(){
        if(front == rear)
            return true;
        return false;    
    }
};

void reverseQueue(Queue *q, int n){
    if(q -> isEmpty())
        return;
    int data = q -> peakFront();
    q -> popFront();
    reverseQueue(q,n);
    q -> pushBack(data);    
}

int main(){

    Queue *q = new Queue(5);

    q -> pushBack(5);
    q -> pushBack(4);
    q -> pushBack(3);
    q -> pushBack(2);
    q -> pushBack(1);

    cout << "Front Element -> " << q -> peakFront() << endl;
    cout << "Back Element -> " << q -> peakBack() << endl;

    // q -> pushBack(10);

    // q -> popFront();
    // cout << "Front Element -> " << q -> peakFront() << endl;
    // cout << "Back Element -> " << q -> peakBack() << endl;

    //queue reversal
    int n = q -> size;
    reverseQueue(q,n);
    cout << "Front Element -> " << q -> peakFront() << endl;
    cout << "Back Element -> " << q -> peakBack() << endl;

}