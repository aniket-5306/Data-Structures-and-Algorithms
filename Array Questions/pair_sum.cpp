#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> v, int s){

    vector<vector<int>> ans;

    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            if(v[i] + v[j] == s){
                vector<int> pair;
                pair.push_back(min(v[i], v[j]));
                pair.push_back(max(v[i], v[j]));
                ans.push_back(pair);
                break;
            }
        }
    }

    sort(ans.begin(),ans.end());
    return ans;

}

int main(){
    // vector<int> v = {0,1,2,3,4,5};
    // int s = 5;
    vector<int> v = {4,-2,5,-1,2,-4,3,-5};
    int s = 0;
    vector<vector<int>> result = pairSum(v,s);
    for(vector<int> pair:result){
        for(int e:pair)
            cout << e << " ";
        cout << endl;    
    }
}