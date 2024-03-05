#include<iostream>
using namespace std;

bool linearSearch(int *a, int n, int key){
    if(n == 0)
        return false;
    if(a[0] == key)
        return true;
    bool ans = linearSearch(a+1, n-1, key);
    return ans;        
}

int main(){
    int arr[] = {5,2,22,13,16,49};
    int size = sizeof(arr)/sizeof(int);
    int key = 22;
    if(linearSearch(arr,size,key)){
        cout << key << " is present in the given array." << endl;
    }
    else{
        cout << key << " is not present in the given array." << endl;
    }
}