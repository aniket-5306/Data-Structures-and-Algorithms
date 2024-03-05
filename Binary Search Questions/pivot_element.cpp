#include<bits/stdc++.h>
using namespace std;

int pivotElement(vector<int> v){
    int s = 0;
    int e = v.size() - 1;
    while(s < e){
        int mid = s + (e - s) / 2;
        if(v[mid] >= v[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return v[s];
}

int main(){
    // vector<int> v = {5,6,1,2,3,4};
    vector<int> v = {8,11,21,27,-3,-2,5,7};

    cout << pivotElement(v);

}