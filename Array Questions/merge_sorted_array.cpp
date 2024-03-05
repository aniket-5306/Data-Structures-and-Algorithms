#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArray(vector<int> a, vector<int> b){

        vector<int> merged_array;

        int i = 0;
        int j = 0;
        while((i < a.size()) && (j < b.size())){
            if(a[i] <= b[j]){
                merged_array.push_back(a[i]);
                i++;
            }
            else{
                merged_array.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()){
            merged_array.push_back(a[i]);
            i++;
        }

        while(j < b.size()){
            merged_array.push_back(b[j]);
            j++;
        }

        return merged_array;

    /*
        // Another solution
        int i = 0;
        int j = 0;
        int p = m;
        while((i < p) && (j < n)){
            if(nums2[j] <= nums1[i]){
                for(int k = p-1; k >= i; k--)
                    nums1[k+1] = nums1[k];
                nums1[i] = nums2[j];
                i++;
                j++;
                p += 1;    
            }
            else{
                i++;
            }
        }
        while((i < (m+n)) && (j < n)){
            nums1[i] = nums2[j];
            i++;
            j++;
        } 
    */        

}

int main(){
    
    vector<int> v1 = {1,5,7,9,15,17,19,27};
    vector<int> v2 = {3,4,7,8,10,12};

    vector<int> mergedArray = mergeSortedArray(v1,v2);

    for(int e:mergedArray){
        cout << e << " ";
    }

}