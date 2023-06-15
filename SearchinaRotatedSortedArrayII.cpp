if arr[] = [3 1 2 3 3 3 3] and target = 1, we need to check if the target appears in the array or not, if it appears we print true otherwise false
'In this type of question we cannott apply Binary search directly or the logic of search in a Rotated Sorted Array we need to modify its code'.
In 'search in a rotated sorted array' we checked for the unsorted half by comparing arr[low] wiht arr[mid] or arr[mid] with arr[high].
The array above have arr[low] == arr[mid] == arr[high], so we are unable to find which half is sorted or not.
so we increase low = low + 1 and decrease high = high - 1.
  
code->
bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    // Write your code here.
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == key)
        {
            return true;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= key && key <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(arr[mid] <= key && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = high - 1;
            }
        }
    }
    return false;
}
TC -> O(n/2)
