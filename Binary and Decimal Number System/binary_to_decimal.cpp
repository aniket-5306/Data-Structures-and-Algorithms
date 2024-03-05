#include<iostream>
#include<math.h>
using namespace std;

int binaryToDecimal(int n){
    int answer = 0;
    int i = 0;
    while(n != 0){
        // int bit = n % 10;
        int bit = n & 1;
        answer += pow(2,i)*bit;
        i++;
        n = n/10;
    }
    return answer;
}

int main(){
    cout << binaryToDecimal(111) << endl;
    cout << binaryToDecimal(1010) << endl;
    cout << binaryToDecimal(1100) << endl;
    cout << binaryToDecimal(101101) << endl;
    cout << binaryToDecimal(101) << endl;
}