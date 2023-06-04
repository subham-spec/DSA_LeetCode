#include <bits/stdc++.h>
using namespace std;
vector<int> minSubsequence(vector<int>& nums) {
        // base condition
        int size = nums.size()-1;
        if(nums.size() == 0)
            return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> l_prefix = nums;
        vector<int> r_prefix(size+1, 0);
        int last = nums[size];
        // making the l_prefix array
        for(int i=1; i<=size; i++)
            l_prefix[i] = nums[i]+l_prefix[i-1];
        // making the right prefix
        for(int i=size-1; i>=0; i--){
            r_prefix[i] = last;
            last += nums[i];
        }

        // vector for the answer
        vector<int> ans;
        for(int i = size; i>=0; i--){
            if(r_prefix[i]<l_prefix[i])
                ans.push_back(nums[i]);
            else{
                if(r_prefix[i] == l_prefix[i])
                    ans.push_back(nums[i]);
                break;
            }
        }
        return ans;
    }

/*
Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

 

Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements. 
Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to be returned in non-decreasing order.  
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 100
*/