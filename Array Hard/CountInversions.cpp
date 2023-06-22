#include <bits/stdc++.h>
using namespace std;
void merge(long long *arr, int low, int mid, int high, long long &count) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            count += (mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long *arr, int low, int high, long long &count) {
    if (low >= high) 
        return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
}
long long getInversions(long long *arr, int n){
    long long count = 0;
    mergeSort(arr, 0, n-1, count);
    return count;
}
int main(){

}


/*
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation Of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
*/