1. Brute Force approach
using linear Search but it will take TC of O(n) which is more than asked in the question we need to do this question in O(logN) time

2. Optimal Solution
using Binary search (but binary search needs sorted array) in this case array is sorted but rotated so after calculating mid we need to find out which part of array (left/right) is sorted.
to check which part is sorted we check that the element at low is less than element at mid, if it is then this half is sorted.
similarly we check for element at high if it is greater than element at mid, it is also sorted half,
but in this case one of the condition will fail.
code ->
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
TC -> O(logN)
