/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/
#include <iostream>
using namespace std;
void generate(string curr, vector<string>& result, int o, int c, int n){
        if(c == n){ 
            result.push_back(curr);
            return;
        }
        if(o<n)
            generate(curr+"(", result, o+1, c, n);
        if(c<o)
            generate(curr+")", result, o, c+1, n);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string curr = "";
        generate(curr, result, 0, 0, n);
        
        return result;
    }