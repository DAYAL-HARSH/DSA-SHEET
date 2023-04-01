#include <bits/stdc++.h>
using namespace std;

int f(int l, int arr[],int r){
    if(l >= r/2) return 0;
    swap(arr[l],arr[r-l-1]);
    f(l+1, arr, r);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    f(0,arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
