1. Brute force approach 
In this approach we used two for loops where we used linear searching to find out the number that appears once and keep a count of it.
if count == 1 then return the number 
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
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == num){
                cnt++;
            }
        }
        if(cnt == 1) {
            cout<<num;
            
        }
    }
  
    return 0;
}
TC -> O(N^2)
SC -> O(1)
  
2. Better Solution
In this approach we used Hashing where we took the hash of whole array and try to find out which array element has hash value as 1 that wil be our answer.
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
    int maxi = arr[0];
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    int hashh[maxi] = {0};
    for(int i = 0; i < n; i++){
        hashh[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(hashh[arr[i]] == 1){
            cout<<arr[i];
        }
    }
    return 0;
}
TC -> O(3N)
SC -> O(MAXI)
  
3. Optimal approach 
In this approach we used XOR method
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
    int xorr = 0;
    for(int i = 0; i < n; i++){
        xorr = xorr ^ arr[i];
    }
    cout<<xorr;
    return 0;
}
TC -> O(N)
SC -> O(1)
