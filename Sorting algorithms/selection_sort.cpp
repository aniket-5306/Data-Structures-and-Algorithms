#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int minPos = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {5,2,9,6,1,11,10,7};
    // int arr[] = {100,90,80,70,60,50,40,30,20,10};
    int n = sizeof(arr) / sizeof(int);
    cout << "Before sorting:";
    printArray(arr,n);
    cout << endl;
    selectionSort(arr,n);
    cout << "After sorting:";
    printArray(arr,n);
}