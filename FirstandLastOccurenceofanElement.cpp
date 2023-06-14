1. Brute Force method
using two variables -> first = -1, last = -1
we will linearly traverse the array if we found 'x' in the array we update the value of both first and last with the index value of x(at which it has found)
Now we will traverse further in the array and if we found another occurence of 'x' on a different index we will update only last.

Pseudo code->
{
  int first = -1, last = -1;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] == x)
    {
      if(first == -1)
      {
        first = i;
      }
      last = i;
    }
  }
  return {first, last};
}
TC -> O(N)

2. Better approach
using both lower and upperbound with some modification
we are using lower bound and upper bound code as it is but we are using an condition to know that the element is present in the array or not.
or lower bound is not pointing to the hypothetical index that is size of array = n
code->
#include <bits/stdc++.h> 
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0;
	int high = n - 1;
	int ans = n;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] >= x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
int upperBound(vector<int> &arr, int n, int x){
	// Write your code here.	
	int low = 0;
	int high = n-1;
	int ans = n;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] > x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb = lowerBound(arr, n, k);
    if(lb == n || arr[lb] != k) return {-1, -1};
    return {lb, upperBound(arr, n, k)-1};
}
TC -> 2*O(logN)
SC -> O(1)
  
3. Optimal approach 
using just binary search
creating two seperate functions for first and last occurences
code->
#include <bits/stdc++.h> 
int FirstOccurence(vector<int> arr, int n, int k) {
	// Write your code here
	int low = 0;
	int high = n - 1;
	int first = -1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == k){
			first = mid;
			high = mid - 1;
		}
		else if(arr[mid] < k){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return first;
}
int LastOccurence(vector<int> arr, int n, int k){
	// Write your code here.	
	int low = 0;
	int high = n-1;
	int last = -1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == k){
			last = mid;
			low = mid + 1;
		}
		else if(arr[mid] < k){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
	int first = FirstOccurence(arr, n, k);
	if(first == -1) return {-1 , -1};
	int last = LastOccurence(arr, n, k);
	return {first, last};
}
TC-> 2*O(logN)
SC-. O(1)
