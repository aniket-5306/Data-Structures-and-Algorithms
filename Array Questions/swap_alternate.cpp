#include<iostream>
using namespace std;

void swapAlternate(int a[], int n){

    if(n % 2 == 0){
        for(int i = 0; i < n;){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            i += 2;
        }
    }
    else{
        for(int i = 0; i < n-1;){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            i += 2;
        }
    }

}

int main(){

    // int arr[] = {2,1,4,3,6,5,8,7,9};
    // int arr[] = {3,5,7,2,4,6,9,1};
    int arr[] = {3,5,7,2,4,6,9,1,0};

    int n = sizeof(arr) / sizeof(int);

    swapAlternate(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

}