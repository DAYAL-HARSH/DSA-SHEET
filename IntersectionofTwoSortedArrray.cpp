1. Brute force approach 
using two nested loops and visited array vis to keep track of elements that has been used/stored already
we iterate through the two loops and compare the first elements of both the arrays if a[i] <= b[j] and vis[j] == 0 then we push a[i] in the answer array
and increase the value of visited by 1 for that value
code-> 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin>>n1;
    cin>>n2;
    int arr1[n1]; 
    int arr2[n2];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>arr2[i];
    }
    int vis[n2] = {0};
    vector<int> ans;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(arr1[i] == arr2[j] && vis[j] == 0){
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if(arr2[j] > arr1[i]) break;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}

TC -> O(N1 * N2)
SC -> O(N2)
  
2. Optimal Approach
In this approach we used two pointer method both pointers are pointing at the first index of both the arrays,
now we compare the elements at both the pointers if pointer1 element is smaller we increase the value of pointer1,
else if the value of element at pointer2 is smaller we increase the value of pointer2, else we push the element into the ans vector.

code->
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin>>n1;
    cin>>n2;
    int arr1[n1]; 
    int arr2[n2];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>arr2[i];
    }
    vector<int> ans;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}

TC -> O(N1 + N2)
SC -> O(1) 
