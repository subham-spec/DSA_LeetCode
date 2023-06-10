#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> assign(int a[], int n){
    
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(a[i]);
    }
    sort(arr.begin(), arr.end());
    int s = 0, e = n-1;

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        if(i&1) {
            ans.push_back(arr[e]);
            --e;
        } else {
            ans.push_back(arr[s]);
            ++s;
        }
    }
    return ans;
}
int main(){
    //take input from user
    int n = 5;
    int arr[] = {2,6,3,5,10};
    assign(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}