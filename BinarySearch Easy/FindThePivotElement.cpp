#include <iostream>
#include <vector>
using namespace std;
int findPivotIndex(vector<int>& arr, int n){
    int ans = 0;
    int low = 0, high = n-1;
    int mid;
    while(low < high) {
        mid = low + (high-low)/2;
        if(arr[mid] >= arr[0])
            low = mid+1;
        else 
            high = mid;
    }
    return high;
}   
int main() {
    vector<int> arr = {7,9,-3,-2,-1,0,1,2,3,4,5,6};
    int index = findPivotIndex(arr, arr.size());

    cout<<index<<endl;
}