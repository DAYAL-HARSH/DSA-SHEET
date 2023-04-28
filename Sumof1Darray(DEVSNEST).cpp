problem statement is that we have to calculate the Running Sum where RunningSum = sum(nums[0] ..... to nums[i]);
after calculating the running sum we have to put the values at the respective indexes

nums[] = [1 2 3 4]
result nums[] = [1 3 6 10] 
explanation -> 1, 1+2, 1+2+3, 1+2+3+4

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int sum = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        sum = arr[i] + sum;
        arr[i] = sum;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

TC-> O(N)
SC-> O(1)
