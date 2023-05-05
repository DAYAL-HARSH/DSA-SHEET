1. Optimal solution
only one solution which is optimal, we used a cnt variable to count the max number of consecutive ones 
if we encounter any other nunber we make cnt = 0 again but before that we store the max value between cnt and maxi into maxi 
code -> 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            cnt++;
            maxi = max(cnt, maxi);
        }
        else {
            cnt = 0;
        }
    }
    cout<<maxi;
    return 0;
}
TC -> O(N)
SC -> O(1)
