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
