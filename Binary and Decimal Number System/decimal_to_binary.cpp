#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int n){
    int answer = 0;
    int i = 0;
    while(n != 0){
        int bit = (n & 1);
        answer = (pow(10,i)*bit) + answer;
        n = n >> 1;
        i++;
    }
    return answer;
}

int main(){
    int decimalNumber;
    cout << "Enter a decimal number:";
    cin >> decimalNumber;
    cout << decimalToBinary(decimalNumber);
}