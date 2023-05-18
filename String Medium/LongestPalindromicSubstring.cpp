/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
using namespace std;
string ans = "";
void expand(string &s , int left ,int right){
    while(left >= 0 &&  right < s.size()){
        if(s[left] != s[right])
            break;
        left--,right++;
    }
    if(ans.size() < right - left )
        ans = s.substr(left + 1 , right - left - 1);
}
string longestPalindrome(string s) {
    for(int i = 0 ; i < s.size() ; i++){
        expand(s , i , i);
        expand(s , i , i+1);
    }
    return ans;
}
int main(){
    string s = "baaabaaabmdwdddddd";
    cout<<longestPalindrome(s)<<endl;
}