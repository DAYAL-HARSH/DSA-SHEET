1. Brute Force 
using two nested loops where i is denoting to the number from 1 to N and j is used to run a loop to find if arr[j] == i,
if it is equal then we increase the value of flag = 1 and break the loop, after that we check if flag == 0 then return i because the number that is missing is present at this i.
code -> 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 1; i < n1; i++) {
        int flag = 0;
        for(int j = 0; j < n1; j++) {
            if(arr1[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout<<i;
        }
    }
    return 0;
}
TC-> O(n*n)
SC-> O(1)
  
2. Better Solution
using Hashing -> we took an hash array to mark the occurence of every element as 1 and after that we check if hash of any element = 0 if it is then it is the missing element so we return the value of i.
code-> 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
    //int n2;
    cin>>n1;
    //cin>>n2;
    int arr1[n1];
    //int arr2[n2];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    int hashh[n1 + 1] = {0};
    
    //for(int i = 0; i < n2; i++) {
    //    cin>>arr2[i];
    //}
    for(int i = 0; i < n1; i++) {
        hashh[arr1[i]] = 1;
    }
    for(int i = 1; i < n1; i++){
        if(hashh[i] == 0){
            cout<<i;
        }
    }
    return 0;
}
TC-> O(N) + O(N)
SC-> O(N)
  
3. Optimal approach 1
