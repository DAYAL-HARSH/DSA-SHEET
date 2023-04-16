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
// we take two pointers as 'i' and 'j'
// i is 0 in the starting and is pointing to the first element in the array
// now j starts from 1(i+1) index and linearly iterates from 1 to n(size of array) and then compare it with arr[i] 
// if the element is same j++
// else we store the element at the next index of i i.e arr[i+1] and i++
CODE-> 
    #include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int i = 0; 
    for(int j = 0; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout<<i+1<<" ";
    return 0;
}
    
    
code -> ON LEETCODE
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return (i+1);
    }
};

TC -> O(N)
SC -> O(1)
    
