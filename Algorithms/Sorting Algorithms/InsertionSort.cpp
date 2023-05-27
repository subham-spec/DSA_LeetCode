#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr, int n){
    int key;
    for(int i=1; i<n; i++){
        key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            // shifting elemens towards right
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n, -1);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    insertionSort(arr, n);
    cout<<"\nOutput for insertion sort is: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';

    return 0;
}
/*

*/