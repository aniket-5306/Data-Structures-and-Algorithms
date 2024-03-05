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

    //stack functions
    void pushElement(int data){
        top++;
        if(top >= size){
            cout << "Stack is Overflow!" << endl;
            top--;
            return;
        }
        arr[top] = data;
        cout << arr[top] << " is pushed into the stack." << endl;
    }

    void popElement(){
        if(top == -1){
            cout << "Stack is Underflow!" << endl;
            return;
        }
        cout << arr[top] << " is popped out!" << endl;
        top--;
    }

    void peakElement(){
        if(top == -1){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top of Stack -> "<< arr[top] << endl;
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;    
    }

    void printStack(){
        int temp = top;
        if(temp == -1){
            cout << "Stack is empty!" << endl;
            return;
        }
        while(temp >= 0){
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }
};

int main(){
    // Stack s(5);  //static memory allocation
    
    Stack *s = new Stack(5);

    s -> pushElement(10);
    s -> pushElement(20);
    s -> pushElement(30);
    s -> pushElement(40);
    s -> pushElement(50);

    s -> printStack();

    s -> popElement();
    s -> peakElement();
    s -> popElement();
    s -> peakElement();
    s -> popElement();
    s -> peakElement();
    s -> popElement();
    s -> peakElement();
    s -> popElement();
    s -> peakElement();

    s -> popElement();

    s -> pushElement(70);
    s -> peakElement();

    if(s -> isEmpty())
        cout << "Yes! Stack is empty." << endl;
    else        
        cout << "Stack is not empty." << endl;
}