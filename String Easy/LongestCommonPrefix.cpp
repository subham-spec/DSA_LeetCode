/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());

        int n = strs.size();
        string first = strs[0];
        string second = strs[n-1];

        for(int i=0; i<min(first.length(), second.length()); i++){
            if(first[i] != second[i])
                return ans;
            ans += first[i];
        }

        return ans;
    }
int main(){
    vector<string> arr = {"flow","flows","flowers"};
    string ans = longestCommonPrefix(arr);

    cout<<ans<<endl;
} 