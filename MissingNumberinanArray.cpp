Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

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
    cin>>n1;
    int arr1[n1];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    int hashh[n1 + 1] = {0};
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
  
3. Optimal approach 
using mathematics
We used the sum of n natural nunber as sum = (n*(n+1))/2 and we also took another variable sum_2 that stores the sum of all the elements of the array,
the missing number is sum - sum_2
*note n is not the size of array
code->
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr1[n-1];
    for(int i = 0; i < n-1; i++) {
        cin>>arr1[i];
    }
    float sum = (n*(n+1))/2;
    int sum_2 = 0;
    for(int i = 0; i < n-1; i++) {
        sum_2 += arr1[i];
    }
    int missing = sum - sum_2;
    cout<<missing;
    return 0;
}
TC -> O(N)
SC -> O(1)

