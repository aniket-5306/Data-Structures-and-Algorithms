#include<iostream>
using namespace std;

bool binarySearch(int *a, int s, int e, int key){
    if(s > e)
        return false;
    int mid = s + (e - s) / 2;
    if(a[mid] == key){
        return true;
    }
    else if(a[mid] > key){
        e = mid - 1;
        bool ans = binarySearch(a,s,e,key);
        return ans;
    }   
    else{
        s = mid + 1;
        bool ans = binarySearch(a,s,e,key);
        return ans;
    } 
}

int main(){
    int arr[] = {2,5,7,17,25,49};
    int size = sizeof(arr)/sizeof(int);
    int key = 19;
    int start = 0;
    int end = size - 1;
    cout << binarySearch(arr,start,end,key) << endl;
}