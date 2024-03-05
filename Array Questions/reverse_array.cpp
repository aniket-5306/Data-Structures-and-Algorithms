#include<iostream>
using namespace std;

void reverseArray(int arr[], int n, int position){
    int i = position + 1;
    int j = n-1;
    while(i <= j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main(){
    int arr[] = {5,3,6,7,1,9};
    int n = sizeof(arr) / sizeof(int);
    int position = 1;

    cout << "Array's element: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    if(position < n-1){

        reverseArray(arr,n,position);

        cout << "Array after reverse: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
}