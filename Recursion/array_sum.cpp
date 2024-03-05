#include<iostream>
using namespace std;

int arraySum(int *a, int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return a[0];
    int result = a[0] + arraySum(a+1,n-1);
    return result;
}

int main(){
    int arr[] = {1,2,3,4,5,9};
    int size = sizeof(arr)/sizeof(int);
    cout << arraySum(arr,size) << endl;
}