/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
        stack<int> ar;
        
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(c == '[' || c == '{' || c == '(') 
                ar.push(c);
            else{
                if(ar.empty())
                    return false;
                char ch = ar.top();
                if((c==']'&& ch=='[') || (c=='}' && ch=='{') || (c==')' && ch=='('))
                    ar.pop();
                else
                    return false;
            } 
        }
        return ar.empty();
}
int main(){
    string s = "()()(){(({{[]}))";
    if(isValid(s))
        cout<<"true";
    else
        cout<<"false";
}