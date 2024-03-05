#include<iostream>
using namespace std;

#define PI 3.14   //macro

inline int greaterNum(int& a, int& b){
    return (a > b) ? a : b;
}

void printArr(int *arr, int size, int start = 0){
    for(int i = start; i < size; i++){
        cout << arr[i] << endl;
    }
}

int main()
{
    int radius = 7;
    double area = PI * radius * radius;
    cout << "Area -> " << area << endl;
    
    int a = 4;
    int b = 3;
    
    int ans = greaterNum(a,b);
    cout << "Greater value -> " << ans << endl;
    
    a += 1;
    b += 4;
    
    ans = greaterNum(a,b);
    cout << "Greater value -> " << ans << endl;
    
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr) / sizeof(int);
    printArr(arr,size,3);
    
}
