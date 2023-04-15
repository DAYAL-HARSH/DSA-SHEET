// Brute force 
// using a set datastructure because set stores only unique elements in sorted order
code->
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int secondLargest = -1;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        cout<<it<<" ";
    }
    return 0;
}

TC -> O(NlogN) + O(N)
SC -> O(N)
  
// Optimal approach
// using 2 pointer approach
