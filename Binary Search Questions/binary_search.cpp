#include<iostream>
using namespace std;

int binarySearch(int e[], int n, int key){

    int start = 0;
    int end = n - 1;

    while(start <= end){

        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;        // optimized expression for bigger value

        if(e[mid] == key)
            return mid;
        else if(key < e[mid])
            end = mid - 1;
        else
            start = mid + 1;        

    }

    return -1;

}

int main(){

    int arr[] = {3,5,10,15,23,25,29};
    int n = sizeof(arr) / sizeof(int);
    int key = 25;

    int index = binarySearch(arr, n, key);

    if(index != -1)
        cout << key << " is present at index -> " << index;
    else    
        cout << key << " is not present in the given array.";

}