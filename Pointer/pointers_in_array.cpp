#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {4, 92, 19, 66};
    cout << "Address of first block -> " << arr << endl;
    cout << "Address of first block -> " << &arr[0] << endl;
    cout << "1st -> " << *arr << endl;
    cout << "2nd -> " << arr[2] << endl;
    cout << "3rd -> " << *(arr + 2) << endl;
    cout << "4th -> " << 3[arr] << endl;
    cout << "5th -> " << *(3 + arr) << endl;
    cout << endl;
    
    int a[10] = {55,12,45,2,8};
    cout << "Address 1st -> " << &a[0] << endl;
    cout << "Address 2nd -> " << a << endl;
    cout << "Address 3rd -> " << &a << endl;
    cout << endl;
    cout << "1st -> " << sizeof(a) << endl;
    cout << "2nd -> " << sizeof(&a) << endl;
    cout << "3rd -> " << sizeof(&a[0]) << endl;
    cout << "4th -> " << sizeof(a[0]) << endl;
    cout << "4th -> " << sizeof(*a) << endl;
    cout << endl;

    int *ptr = &a[0];
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << ptr++ << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << endl;



    // pointer concept for char arrays 
    int num[10] = {43, 21, 5, 29};
    cout << num << endl;

    char ch[10] = "aniket";
    cout << ch << endl;

    int *iptr = &num[0];
    cout << iptr << endl;

    char *cptr = &ch[0];
    cout << cptr << endl;


    char alpha = 'z';
    cout << alpha << endl;
    char *c = &alpha;
    cout << c << endl;


}
