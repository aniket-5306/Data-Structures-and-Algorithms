#include<bits/stdc++.h>
using namespace std;

vector<int> sumOfTwoArrays(vector<int> a, vector<int> b){

    vector<int> resultingArray;

    int num1 = 0;
    int m = a.size()-1;
    for(int i = 0; i < a.size(); i++){
        num1 += a[i] * pow(10,m);
        m--;
    }

    int num2 = 0;
    int n = b.size()-1;
    for(int j = 0; j < b.size(); j++){
        num2 += b[j] * pow(10,n);
        n--;
    }

    int result = num1 + num2;

    while(result != 0){
        int digit = result % 10;
        resultingArray.push_back(digit);
        result = result / 10;
    }

    reverse(resultingArray.begin(), resultingArray.end());

    return resultingArray;

}

int main(){
    vector<int> v1 = {8,0,0,0};
    vector<int> v2 = {9,0,0,0,0};

    vector<int> resultingArray = sumOfTwoArrays(v1,v2);

    for(int i:resultingArray){
        cout << i << " ";
    }
}