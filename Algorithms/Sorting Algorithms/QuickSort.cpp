#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// partitioning function
int partition(vector<int> &arr, int s, int e) {
    int pivot = arr[e];
    int k = s;
    for(int i=s; i<e; i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[k]);
            k++;
        }
    }
    swap(arr[e], arr[k]);
    return k;
}
// function for quick sort
void quickSort(vector<int> &arr, int s, int e){
    if(s >= e) 
        return;
    int p = partition(arr, s, e);
    // left side partitioning
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of teh array : ";

    for(int i=0; i<size; i++)
        cin>>arr[i];

    quickSort(arr, 0, size-1);

    // printing the whole array
    for(auto i: arr)
        cout<<i<<' ';
}