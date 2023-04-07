//Intution -> push the maximum to the last by adjacent swapping

#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int arr[], int n){
    for(int i = 0; i <= n-2; i++){
        int minimum = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[minimum]) minimum = j;
        }
        int temp = arr[minimum];
        arr[minimum] = arr[i];
        arr[i] = temp;
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
