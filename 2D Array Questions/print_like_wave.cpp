#include<iostream>
using namespace std;

void printWave(int arr[][3], int n){
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){    
            for(int j = 0; j < n; j++)
                cout << arr[j][i] << " ";
        }
        else{
            for(int j = n-1; j >= 0; j--)
                cout << arr[j][i] << " ";
        }
    }
}

int main(){

    int arr[3][3];

    cout << "Enter array's elements:" << endl;
    // row wise input
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    cout << "Array's elements are:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;    
    }
    cout << endl;

    printWave(arr,3);

}