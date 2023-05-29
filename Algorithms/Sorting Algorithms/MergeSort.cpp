#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// merging the array
void merge(vector<int>& arr, int s, int mid, int e){
    int len1 = mid-s+1;
    int len2 = e-mid;

    vector<int> l(len1);
    vector<int> r(len2);
    // storing the values of both sides.
    int mi = s;
    for(int i=0; i<len1; i++)
        l[i] = arr[mi++];

    mi = mid+1;
    for(int i=0; i<len2; i++)
        r[i] = arr[mi++];


    int i=0, j = 0;
    mi = s;
    while(i<len1 && j<len2){
        if(l[i] < r[j])
            arr[mi++] = l[i++];
        else
            arr[mi++] = r[j++];
    }
    while(i<len1)
        arr[mi++] = l[i++];
    while(j<len2)
        arr[mi++] = r[j++];
}
// diving into parts
void divide(vector<int>& arr, int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    divide(arr, s, mid);
    divide(arr, mid+1, e);

    merge(arr, s, mid, e);
}
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of teh array : ";

    for(int i=0; i<size; i++)
        cin>>arr[i];

    divide(arr, 0, size-1);

    // printing the whole array
    for(auto i: arr)
        cout<<i<<' ';
}