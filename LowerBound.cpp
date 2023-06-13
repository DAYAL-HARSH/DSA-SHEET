code-> 
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
IN C++ only we can use lower_bound inbuilt function
code -> 
#include<bits/stdc++.h>
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	return lb;
}
