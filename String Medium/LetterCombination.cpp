/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> result;
vector<string> dialpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void rec(string& digits, vector<string>& result, string s, int i, int n){
        if(i == n){
            result.push_back(s);
            return;
        }
        char dig = digits[i];
        string possible = dialpad[dig-'0'];

        for(int j=0; j<possible.size(); j++)
            rec(digits, result, s+possible[j], i+1, n);
        
}
vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.length();
        if(n<1)
            return result;
        string s = "";
        rec(digits, result, s, 0, n);
        return result;
}
