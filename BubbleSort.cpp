//Intution -> push the maximum to the last by adjacent swapping

#include<bits/stdc++.h>
using namespace std;


void selection_sort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    return 0;
}
