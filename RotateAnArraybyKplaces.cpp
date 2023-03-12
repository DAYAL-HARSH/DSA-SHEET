#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int k)
{
    reverse(arr,arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    leftRotate(arr, n, k);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
