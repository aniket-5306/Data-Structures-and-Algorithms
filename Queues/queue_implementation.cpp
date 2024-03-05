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

    void pushInQueue(int data){
        if(rear >= size){
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    void popFromQueue(){
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
        front++;
    }

    int frontOfQueue(){
        if(front == rear){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int backOfQueue(){
        if(front == rear){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear - 1];
    }

    bool isEmpty(){
        if(front == rear)
            return true;
        return false;    
    }
};

int main(){
    
    Queue *q = new Queue(2);

    q -> pushInQueue(1);
    q -> pushInQueue(2);
    // q -> pushInQueue(3);
    // q -> pushInQueue(4);
    // q -> pushInQueue(5);
    // q -> pushInQueue(6);
    // q -> pushInQueue(7);
    // q -> pushInQueue(8);

    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> popFromQueue();
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> popFromQueue();
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    cout << q -> front << endl;
    cout << q -> rear << endl;

    q -> pushInQueue(10);
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> pushInQueue(20);
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> pushInQueue(30);

    q -> popFromQueue();
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> popFromQueue();
    cout << "front element -> " << q -> frontOfQueue() << endl;
    cout << "back element -> " << q -> backOfQueue() << endl;

    q -> popFromQueue();

}