// optimal solution
// in this question the positive numbers always appears at the even indexes and negative at the odd indexes, so we took an empty array ans and placed positive nums 
// on the even indexes and negative on the odds.
// arr = [posi, nega, posi, nega, posi, nega]
// in this array it is given thath the no. of positive is equal to no. of negatives

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int positiveIndex = 0, negativeIndex = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
            else {
                ans[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
        }
        return ans;
    }
};

// variety of above question 
// in this ques the number the no. of positive are not equal to no. of negatives
// so the above optimal approach will not work because its dependent when the no. of positive and negative are same

vector<int> alternateNumbers(vector<int>&a) {
    int n = a.size();
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i = neg.size(); i < pos.size(); i++){
            a[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i = 0; i < pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i = pos.size(); i < neg.size(); i++){
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}
