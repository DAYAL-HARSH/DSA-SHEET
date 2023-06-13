1. Iterative Binary Search pseudo code->
code->
int solve(int n, vector<int> nums, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


2. Recursive Binary Search Pseudo code->
code->
int Binary_search(vector<int>& nums, int low, int high, int target)
{
    if(low > high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    if(nums[mid] == target){
        return mid;
    }
    else if(target > nums[mid]){
        return Binary_search(nums, mid+1, high, target);
    }
    return Binary_search(nums, low, mid-1, target);
}

int search(vector<int>& nums, int target) {
    // Write Your Code Here
    return Binary_search(nums, 0, nums.size()-1, target);
}
