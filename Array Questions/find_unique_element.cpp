#include<bits/stdc++.h>
using namespace std;

/*
int findUnique(vector<int> fe){
    vector<int> unique(fe.size(), 1);
    for(int i = 0; i < fe.size()-1; i++){
        if(unique[i] != 0){
            for(int j = i+1; j < fe.size(); j++){
                if(fe[j] == fe[i]){
                    unique[j] = 0;
                    unique[i] = 0;
                }
            }
        }
    }

    int gotUnique = -1;
    for(int i = 0; i < fe.size(); i++){
        if(unique[i] == 1)
            gotUnique = i; 
    }

    return fe[gotUnique];

}
*/

// optimized solution
int findUnique(vector<int> vc){
    int ans = 0;
    int i = 0;
    while(i < vc.size()){
        ans ^= vc[i];
        i++;
    }
    return ans;
}

int main(){

    vector<int> v = {3, 5, 6, 5, 3, 7, 6};

    cout << findUnique(v) << endl;

}