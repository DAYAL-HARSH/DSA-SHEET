1. Brute force 
we used and temporary array to store the non zero elements and replace them in the front of the array and put all the zeros after them 
we used three for loops to do this.
  code-> 
  class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
            
        }
        int nz = temp.size();
        for(int i = nz; i < n; i++){
            nums[i] = 0;
        }
    }
};

TC -> O(2N)
SC -> O(N)
  
2. Optimal Solution 
using two pointer approach where first pointer is pointitng to the first zero in the array and the second pointer is pointing at the j+1 position
if we find that arr[j+1] != 0 then we swap it with arr[j] and increment j
code-> 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j;
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        for(int i = j + 1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

TC-> O(N)
SC-> O(1)
