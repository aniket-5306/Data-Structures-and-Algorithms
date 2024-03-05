#include<iostream>
#include<string>
using namespace std;

class Stack{
    public:
    char *arr;
    int size;
    int top;

    Stack(int size){
        this -> size = size;
        arr = new char[size];
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
    }

    char popElement(){
        char popedElement = arr[top];
        top--;
        return popedElement;
    }

    char peakElement(){
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;    
    }
};

int main(){
    
    string str = "Happy New Year 2024 :)";
    int strSize = str.size();
    Stack *s = new Stack(strSize);

    cout << "Original str -> " << str << endl;

    for(int i = 0; i < strSize; i++){
        s -> pushElement(str[i]);
    }

    // s -> peakElement();
    int i = 0;
    while(!s->isEmpty() && i < strSize){
        str[i] = s -> popElement();
        i++;
    }

    cout << "Reversed str -> " << str << endl;

}