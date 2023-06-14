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
}int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int, int> ans = firstAndLastPosition(arr,n,x);
	if(ans.first == -1) return 0;
	return ans.second - ans.first + 1;
}
TC-> 2*O(logN)
SC-> O(N);
