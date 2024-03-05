#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArrays(vector<int> p, vector<int> q){

    vector<int> ans;

/*
    for(int i = 0; i < p.size(); i++){
        for(int j = 0; j < q.size(); j++){
            if(p[i] == q[j]){
                ans.push_back(p[i]);
                q[j] = INT_MIN;
                break;
            }
        }
    }
*/


// optimize solution using two pointer approach
    int i = 0; 
    int j = 0;

    while((i < p.size()) && (j < q.size())){
        if(p[i] < q[j]){
            i++;
        }
        else if(p[i] == q[j]){   
            ans.push_back(p[i]);
            i++;
            j++;    
        }
        else{
            j++;
        }
    }

    return ans;

}

int main(){
    vector<int> a = {2,4,6,7,7,9,13,13,15,20,22,25,29,29,37};
    vector<int> b = {1,3,4,5,7,8,13,13,13,15,29};

    vector<int> intersectionedElements = intersectionOfArrays(a,b);

    for(int element:intersectionedElements)
        cout << element << " ";
}