// Better approach
code -> 
  #include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            set<long long> hashset;
            for(int k = j + 1; k < n; k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long forth = target - (sum);
                if(hashset.find(forth) != hashset.end()){
                  vector<int> temp = {nums[i], nums[j], nums[k], (int)forth};
                  sort(temp.begin(), temp.end());
                  st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal approach 
code -> 
  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> res;
        
        if(nums.empty()){
            return res;
        }
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n; j++){
                
                long long target_2 = target - (nums[j] + nums[i]);

                int front = j + 1;
                int back = n - 1;
                
                while(front < back){
                    int twosum = nums[front] + nums[back];
                    
                    if(twosum < target_2) front++;

                    else if(twosum > target_2) back--;
                    
                    else{
                        vector<int> quadruple(4,0);
                        quadruple[0] = nums[i];
                        quadruple[1] = nums[j];
                        quadruple[2] = nums[front];
                        quadruple[3] = nums[back];
                        res.push_back(quadruple);

                        while(front < back && nums[front] == quadruple[2]) ++front;
                        while(front < back && nums[back] == quadruple[3]) --back;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;

        }
        return res;
    }
};


codestudio code -> 
#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < n; j++){
            if(j != (i+1) && nums[j] == nums[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                  vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                  ans.push_back(temp);
                  k++;
                  l--;
                  while(k < l && nums[k] == nums[k-1]) k++;
                  while(k < l && nums[l] == nums[l+1]) l--;
                } 
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}
