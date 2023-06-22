#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp; // temporary numsay
        int left = low;      // starting index of left half of nums
        int right = mid + 1;   // starting index of right half of nums

        //storing elements in the temporary numsay in a sorted manner//
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        // if elements on the left half are still left //
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        // transfering all elements from temporary to nums //
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    
    int countPairs(vector<int> &nums, int low,int mid, int high) {
        int right=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++) {
            while(right<=high && nums[i]> 2* (long long) nums[right])
                ++right;
            cnt += (right-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low >= high) 
            return 0;
        int mid = (low + high) / 2 ;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/