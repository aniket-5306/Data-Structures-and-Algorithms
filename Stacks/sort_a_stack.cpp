#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    void push(int data){
        top++;
        if(top >= size){
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

    void insertAtCorrectPosition(int element){
        if(top == -1 || element >= this -> peak()){
            this -> push(element);
            return;
        }
        int data = this -> peak();
        this -> pop();
        insertAtCorrectPosition(element);
        this -> push(data);
    }

    void sortStack(){
        if(top == -1){
            return;
        }
        int element = this -> peak();
        this -> pop();
        sortStack();
        insertAtCorrectPosition(element);
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

    s -> push(2);
    s -> push(5);
    s -> push(1);
    s -> push(3);
    s -> push(4);
    // s -> push(6);
    // cout << "Peak Element -> " << s -> peak() << endl;

    // s -> pop();
    // cout << "Peak Element -> " << s -> peak() << endl;

    cout << "Original Stack -> ";
    s -> printStack();
    cout << "Peak Element -> " << s -> peak() << endl;

    cout << "Sorted Stack -> ";
    s -> sortStack();
    s-> printStack();
    cout << "Peak Element -> " << s -> peak() << endl;

}