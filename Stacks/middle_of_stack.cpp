#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        top++;
        if(top == size){
            cout << "Stack Overflow!" << endl;
            top--;
            return;
        }
        arr[top] = data;
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top] = 0;
        top--;
    }

    int peak(){
        if(top == -1){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;    
    }

    void printStack(){
        if(top == -1){
            cout << "Stack is empty!" << endl;
            return;
        }
        int i = 0;
        while(i <= top){
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
};

int main(){
    Stack *s = new Stack(5);
    s -> push(1);
    s -> push(2);
    s -> push(3);
    s -> push(4);
    s -> push(5);
    // s -> push(6);

    cout << "Original Stack -> ";
    s -> printStack();

    cout << "Peak Element -> " << s -> peak() << endl;

    int mid = (s -> size - 1) / 2;
    Stack *ds = new Stack(s -> size - mid - 1);

    while(s -> top > mid){
        int data = s -> peak();
        ds -> push(data);
        s -> pop();
    } 
    //removal of middle element
    s -> pop();

    // s -> printStack();
    // ds -> printStack();
    // cout << ds -> size << endl;

    while(!ds -> isEmpty()){
        int data = ds -> peak();
        s -> push(data);
        ds -> pop();
    }

    cout << "After Deletion of middle element, Stack -> ";
    s -> printStack();

}