#include <bits/stdc++.h>
#include <sstream> 
using namespace std;
string sortSentence(string s) {
        vector<pair<string, int>> words;
        
        // Split the sentence into words and their positions
        stringstream ss(s);
        string word;
        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();
            words.push_back({word, pos});
        }
        
        // Sort the words based on their positions
        sort(words.begin(), words.end(),[](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second;
        });
        
        // Reconstruct the original sentence
        string original;
        for (const auto& w : words) {
            original += w.first + " ";
        }
        
        // Remove the trailing space
        original.pop_back();
        
        return original;
    }
/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
*/