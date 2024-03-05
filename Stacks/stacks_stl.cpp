#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;   //creating stack

    s.push(10);     //inserting element into stack(push)
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Size of stack -> " << s.size() << endl;

    cout << s.top() << endl;    //inspecting top element of the stack(peek)

    while(!s.empty()){
        s.pop();    //removing element from the stack(pop)
        if(!s.empty())
            cout << s.top() << endl;
    }

    if(s.empty())   
        cout << "Stack is empty!" << endl;
    else{
        cout << "Stack is not empty." << endl;
    }    

    //swap function
    s.push(1);     //inserting element into stack(push)
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stack<int> s2;
    s2.push(100);
    
    s.swap(s2);

    cout << "Stack(s) elements -> ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();    //removing element from the stack(pop)
    }cout << endl;

    cout << "Stack(s2) elements -> ";
    while(!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();    //removing element from the stack(pop)
    }cout << endl;
    
}