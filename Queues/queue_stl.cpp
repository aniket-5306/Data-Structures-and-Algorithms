#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);

    cout << "size of queue -> " << q.size() << endl;

    q.pop();
    cout << "size of queue -> " << q.size() << endl;

    cout << "front element of queue -> " << q.front() << endl;
    cout << "back element of queue -> " << q.back() << endl;

    if(q.empty()){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Queue is not empty!" << endl;
    }

}