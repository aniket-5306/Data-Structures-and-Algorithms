#include<bits/stdc++.h>
using namespace std;

int totalOccurence(vector<int>& nums, int target) {

        int leftmostIndex = -1;
        int rightmostIndex = -1;

        // finding index of leftmost occurence
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == target){
                leftmostIndex = mid;
                e = mid - 1;
            }
            else if(target < nums[mid])
                e = mid - 1;
            else 
                s = mid + 1;    
        }

        // finding index of rightmost occurence
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                rightmostIndex = mid;
                start = mid + 1;
            }
            else if(target < nums[mid])
                end = mid - 1;
            else 
                start = mid + 1;    
        }

        if(leftmostIndex != -1 || rightmostIndex != -1)
            return (rightmostIndex - leftmostIndex + 1);

        return 0;    
}


int main(){

    vector<int> v = {-2,-2,-2,-2,-1,4,5,7,7,7,10};
    int target = -2;

    cout << "Total occurence of " << target << " -> " << totalOccurence(v,target);

}