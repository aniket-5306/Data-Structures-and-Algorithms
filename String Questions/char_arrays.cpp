#include<iostream>
using namespace std;

int getLength(char name[]){
    int len = 0;
    for(int i = 0; name[i] != '\0'; i++){
        len++;
    }
    return len;
}

string reverseString(char name[], int length){
    int s = 0;
    int e = length - 1;
    while(s <= e){
        swap(name[s], name[e]);
        s++;
        e--;
    }
    return name;
}

int main(){
    char name[20];
    cout << "Enter your name:" << endl;
    cin >>  name;
    // name[3] = '\0';
    cout << "Your name is " << name << endl;

    // cout << "Length of your name is " << getLength(name) << endl;

    int length = getLength(name);

    cout << "Reversed name is " << reverseString(name, length);

}