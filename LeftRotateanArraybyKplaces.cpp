1. Brute force approach

code-> 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }
    for(int i = k; i < n; i++){
        arr[i-k] = arr[i];
    }
    for(int i = n-k; i < n; i++){
        arr[i] = temp[i-(n-k)];
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

TC -> O(N)
SC -> O(K)

2. Optimal Approach

code-> 
  #include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    k = k % n;
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

TC-> O(2N)
SC-> O(1)

  
