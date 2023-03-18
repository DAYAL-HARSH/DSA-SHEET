// brute force approach 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

// better solution 
// using three counter variable 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) cnt_0++;
            else if(nums[i] == 1) cnt_1++;
            else cnt_2++;
        }
        int l = cnt_0;
        int m = cnt_0 + cnt_1;
        for(int i = 0; i < l; i++) nums[i] = 0;
        for(int i = l; i < m; i++) nums[i] = 1;
        for(int i = m; i < n; i++) nums[i] = 2;
    }
};

// optimal solution  
// using DNF(Dutch National Flag) algo
// In DNF there are three conditions 
// 1. from 0 to low-1 there will be all 0's.
// 2. from low to mid-1 there will be all 1's.
// 3. from high+1 to n-1 there will be all 2's.
// and from mid+1 to high all the elements are unsorted and contains all 0,1 and 2.

// algorithm
step 1 :->
arr[mid] == 0 
  swap(a[low],a[mid]); 
  low++;
  mid++;
step 2 :->
arr[mid] == 1
  mid++
step 3 :->
arr[mid] == 2
  swap(arr[mid],arr[high]);
  high--;
  
//code
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
