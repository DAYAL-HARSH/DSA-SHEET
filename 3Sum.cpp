// 1. brute force approach
// In brute force appraoch we will use three loops and try all the triplets that have the sum = 0 and we will use a SET data structure to store triplets to eliminate
// duplicates 
//code -> 
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                  vector<int> temp = { arr[i], arr[j], arr[k] };
                  sort(temp.begin(), temp.end());\
                  st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// 2. better solution 
// using hashing 
//we will run two loops for a and b and using hashing for c 
//a + b + c = 0 -> c = -(a+b)
//  pseudo code->
  
  for(i = 0 to n-1){
    hash[a[i]]--;
    for(j = i+1 to n-1){
        hash[a[j]]--;
        find this in the array 'c' = -> -(a[i]+a[j])
    }
      hash[a[j]]++;
  }
  hash[a[i]]++;
  

// 3. optimal approach
// uisng two pointer approach 
// first step -> sort the array 
// second step is to take 'a' as a constant 
// now the problem looks like 2 sum problem
// b+c = -a 
// now take two pointers lo and hi 
// a = arr[i] lo = arr[i+1] hi = arr[n-1]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size()-2; i++){
            
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                
                int lo = i+1, hi = nums.size()-1, sum = 0 - nums[i];

                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);

                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;

                        lo++;
                        hi--;
                    }
                    else if(nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
                }
            }
        }
        return res;
    }
};
