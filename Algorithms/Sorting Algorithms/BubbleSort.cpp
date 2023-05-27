#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 6;
    vector<int> arr = {6,0,3,5,2,1};

    // bubble sort algorithm
    bool counter = true;
    int settled = 0;
    while(counter){
        counter = false;
        for(int i=1; i<n-settled; i++){
            if(arr[i]<arr[i-1]){
                swap(arr[i], arr[i-1]);
                counter = true;
            }
        }
    }

    cout<<"Output array is: ";
    for(auto i: arr){
        cout<<i<<' ';
    }
    return 0;
}