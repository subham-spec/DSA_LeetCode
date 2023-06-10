#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
        int i=0, j=0, l=nums.size();
        while(j < l){
            if(nums[i]!=0 && nums[j]!=0){
                ++i, ++j;
            }
            else{
                while(j < l && nums[j]==0)
                    ++j;
                if(j == l)
                    return;
                else{
                    swap(nums[i], nums[j]);
                    ++i, ++j;
                }
            }
        }
    }
int main(){

}

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/