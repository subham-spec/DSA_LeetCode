#include <bits/stdc++.h>
#include <map>
using namespace std;

int countPrefixSum(vector<int> &arr, int k){
    int preSum = 0;
    int count = 0;
    map<int, int> mp;
    mp[0] = 1;

    for(auto i: arr){
        preSum += i;
        count += mp[preSum-k];
        mp[preSum] += 1;
    }
}

int main(){

}


/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/