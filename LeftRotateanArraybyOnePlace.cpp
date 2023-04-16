// optimal approach
// In this approach we assign a temp variable which store the value of arr[0]
// now from arr[1] to arr[n] we linearly iterate in the array
// replacing the element at arr[i-1] to arr[i]
code-> 
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int temp = arr[0]; 
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

TC -> O(N)
SC -> O(1)
