#include <iostream>
#include <vector>
using namespace std;
void doSelectionSort(int n, vector<int> &arr){
    int mini;
    for(int i=0; i<n-1; i++){
        mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[mini]>arr[j])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    doSelectionSort(n, arr);
    for(auto i: arr)
        cout<<i<<' ';
}