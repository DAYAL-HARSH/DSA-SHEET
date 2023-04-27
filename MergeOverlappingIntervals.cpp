// Brute force approach
// In this approach we firstly sort the array and then combine the array if the first element of second pair is smaller than the second element of  the first pair.
// if it is true then we combine them together and create a new pair with first element of first pair and max(second element of both pairs)
#include<bits/stdc++.h>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++){
		int start = arr[i][0];
		int end = arr[i][1];
		if(!ans.empty() && end <= ans.back()[1]){
			continue;
		}
		for(int j = i + 1; j < n; j++){
			if(arr[j][0] <= end){
				end = max(end, arr[j][1]);
			}
			else{
				break;
			}
		}
		ans.push_back({start, end});
	}
	return ans;
}

TC -> O(nlogn) + o(2n)
SC -> O(n)
  
// optimal approach 
// reducing the looping doing it in one pass
code->
  #include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for(int i = 0;i<n;i++){
		if(ans.empty() || arr[i][0] > ans.back()[1]){
			ans.push_back(arr[i]);
		}
		else{
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}
	}
	return ans;
}

TC -> O(nlogn) + O(n)
SC -> O(n)
