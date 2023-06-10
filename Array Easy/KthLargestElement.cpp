#include <iostream>
#include <queue>
using namespace std;
int findKthLargest(vector<int> arr, int k){
    int ans = -1;
    // making a priority queue
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++){
        pq.push(arr[i]);
    }
    while(k>0){
        ans = pq.top();
        pq.pop();
        k--;
    }
    return ans;
}
int main(){
    vector<int> arr = {10, 4, 3, 50, 23, 90};
    int k = 3;

    int element = findKthLargest(arr, k);
    cout<<k<<"th largest element is: "<<element<<endl;
}