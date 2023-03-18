// better solution approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // better solution
        int n = nums.size();
        map<int, int> mpp;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more],i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};
Time complexity = O(N*logN)
    

// optimal solution 

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(),book.end());
    while(left < right){
        for(int i = 0; i < n; i++){
            int sum = book[left] + book[right];
            if (sum == target) {
              return "YES";
            } else if (sum < target)
              left++;
            else
              right--;
        }
    }
    return "NO";
}
// *note = this optimal solution is only for yes or no type of question
Tc - O(N)
