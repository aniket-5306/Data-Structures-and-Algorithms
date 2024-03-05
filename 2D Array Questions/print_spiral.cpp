#include<bits/stdc++.h>
using namespace std;

void printSpiral(int arr[][3], int n){

    int startingRow = 0;
    int endingRow = n - 1;
    int startingCol = 0;
    int endingCol = n - 1;

    int count = 0;
    int totalCount = n*n;

    while(count < totalCount){

        //printing starting row's elements
        for(int index = startingCol; count < totalCount && index <= endingCol; index++){
            cout << arr[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        //printing ending col's elements
        for(int index = startingRow; count < totalCount && index <= endingRow; index++){
            cout << arr[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        //printing ending row's elements
        for(int index = endingCol; count < totalCount && index >= startingCol; index--){
            cout << arr[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        //printing starting col's elements
        for(int index = endingRow; count < totalCount && index >= startingRow; index--){
            cout << arr[index][startingCol] << " ";
            count++;
        }
        startingCol++;

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

    printSpiral(arr,3);

}