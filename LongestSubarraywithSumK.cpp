1. Brute Force Approach
In this approach we generated all the subarray and calculated the sum after that we compared the sum == k and returned the length of the array till then.
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
    int k;
    cin>>k;
    
    int len = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            if(sum == k){
                len = max(len, j-i+1);
                
            }
        }
    }
  
    cout<<len;
    return 0;
}
TC -> ~ O(N^3)
SC -> O(1)

2. Better Solution
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
    int i = 0, j = 0;
    int len = 0;
    for(i = 0; i < n; i++){
        int sum = 0;
        for(j = i; j < n; j++){
            sum += arr[j];
            if(sum == k){
                len = max(len, j-i+1);
                
            }
        }
    }
    cout<<len;
    return 0;
}
TC -> O(N^2)
SC -> O(1)

2. Optimal solution for only positive elements in array
using Hashing 
we will use hashmap that contains (presum, index)
we use two variable as sum = 0 and len(length of largest subarray) = 0
now we iterate in the array and increase the value of sum and if it becomes equivalent to k we store the length of subarray in len.
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
    int k;
    cin>>k;
    int sum = 0;
    int maxlen = 0;
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == k){
            maxlen = max(maxlen, i+1);
        }
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(maxlen, len);
        }
        mpp[sum] = i;
    }
    cout<<maxlen;
    return 0;
}
TC -> O(N) OR O(NLOGN) #Depending upon which map you choose
SC -> O(N)
*NOTE - This code only runs for positive numbers

3. Optimal approach
This code will work for both cased where a array contains both positive and negative number/elements
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
    int k;
    cin>>k;
    int sum = arr[0];
    int maxlen = 0;
    int left = 0, right = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    cout<<maxlen;
    return 0;
}
TC -> O(2N)
SC -> O(1)
