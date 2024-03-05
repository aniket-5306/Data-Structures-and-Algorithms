#include <iostream>
using namespace std;

bool linearSearch(int arr[][3], int m, int n, int key){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == key)
                return 1;
        }
    }
    return 0;
}

void colWiseSum(int arr[][3], int m, int n){
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += arr[j][i];
        }
        cout << (i+1) << "th col sum -> " << sum << endl;
    }
}

int largestRowSum(int arr[][3], int m, int n){
    int maxSum = -99999;
    int index = -1;
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += arr[i][j];
        }
        if(sum > maxSum){
            maxSum = sum;
            index = i;
        }
    }
    return index;
}


int main()
{
    int a[3][3];
    
    cout << "Enter array's elements:" << endl;
    // row wise input
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    
    // // column wise input
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++)
    //         cin >> a[j][i];
    // }
    
    cout << "Array's elements are:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;    
    }
    cout << endl;
    
    int m = 3;
    int n = 3;
    int key = 5;
    
    // cout << linearSearch(a,m,n,key);
    
    // colWiseSum(a,m,n);
    
    cout << "Row having largest sum -> " << largestRowSum(a,m,n) << endl;
    
}