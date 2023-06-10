#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        int ans = 0;
        while(nums[ans] != -1){
            int pos = nums[ans];
            nums[ans] = -1;
            ans = pos;
        }
        return ans;
    }


/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
*/