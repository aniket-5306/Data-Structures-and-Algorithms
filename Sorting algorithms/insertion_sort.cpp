#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        int k = -1;
        while(j >= 0){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
                k = j;
            }
            else{
                break;
            }
            j--;
        }
        if(k != -1)
            arr[k] = temp; 
    }
}

int main(){

    // int arr[] = {90,80,70,60,50,40,30,20,10};
    int arr[] = {5,1,7,9,5,3,5,4};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array before sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr,n);
    
    cout << "Array after sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

}