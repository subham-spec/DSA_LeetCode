/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <iostream>
#include <set>
using namespace std;
int lengthOfLongestSubstring(string s) {
    set<char> st;
    int maxi = 0;
    int start = 0;
    for(int i=0; i<s.length(); i++){
        if(!st.count(s[i])){
            st.insert(s[i]);
            int size = st.size();
            maxi = max(maxi, size);
        }
        else{
            while(st.count(s[i])){
                st.erase(s[start]);
                start++;
            }
            st.insert(s[i]);
        }
    }
    return maxi;
}
int main(){
    string s = "Iamtheonlyoneguyonthisearth";
    cout<<lengthOfLongestSubstring(s)<<endl;
}