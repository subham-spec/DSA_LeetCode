#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;

        // checking possiblity
        int arr[26] = {0};
        for(int i=0; i<s.size(); i++){
            arr[s[i]-97]++;
        }

        int odd_count = 0;
        for(int i=0; i<26; i++)
            if(arr[i]%2 == 0 && arr[i]!=0)
                ++odd_count;
        
        if(odd_count>1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}