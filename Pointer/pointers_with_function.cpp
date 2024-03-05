#include<iostream>
using namespace std;

void print(int *p){
    cout << *p << endl;
    cout << p << endl;
}

void update(int *p){
    *p = *p * 5;
    // p = p + 1;
}

// int findSum(int arr[], int n){
//     cout << sizeof(arr) << endl;
//     int sum = 0;
//     for(int i = 0; i < n; i++)
//         sum += arr[i];
//     return sum;
// }

int findSum(int *ptr, int n){
    cout << sizeof(ptr) << endl;
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += ptr[i];
    return sum;
}

int main(){

    int num = 5;
    int *p = &num;

    cout << "Before update -> ";
    print(p);
    cout << endl;

    update(p);

    cout << "After update -> ";
    print(p);
    cout << endl;


    int arr[7] = {1,2,3,4,5,6,7};

    int totalSum = findSum(arr,7);

    cout << "Sum -> " << totalSum << endl;

}