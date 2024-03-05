#include<iostream>
using namespace std;

bool isSorted(int a[], int n){
    if(n == 0 || n == 1)
        return true;
    if(a[0] > a[1])
        return false;
    bool ans = isSorted(a+1, n-1);
    return ans;        
}

int main(){
    int arr[] = {2,4,3,7,9,11};
    int size = sizeof(arr)/sizeof(int);
    cout << isSorted(arr,size) << endl;
}