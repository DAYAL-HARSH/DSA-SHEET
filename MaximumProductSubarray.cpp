1. Brute force approach
create all subarray using three nested loops 
code-> 
#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int maxi = INT_MIN;
	for(int i = 0; i < arr.size() - 1; i++){
		for(int j = i + 1; j < arr.size(); j++){
			int prod = 1;
			for(int k = i; k <= j; k++){
				prod *= arr[k];
			}
			maxi = max(maxi, prod);
		}
	}
	return maxi;
}
TC -> O(N^3)
SC -> O(1)
//This code will only work until the array doesn't contains zero
  
 2. Better Solution
 using one less loop to reduce time complexity
 code-> 
#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int maxi = INT_MIN;
	for(int i = 0; i < arr.size() - 1; i++){
		int prod = 1;
		for(int j = i + 1; j < arr.size(); j++){
			prod *= arr[j];
			
		}
		maxi = max(maxi, prod);
		
	}
	return maxi;
}
TC -> O(N^2)
SC -> O(1)
 
3. Optimal code
using two variables prefix as pre and suffix as suff, we are iterating from front for pre and from back for suff
code->
#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int n = arr.size();
	int maxi = INT_MIN;
	int pre = 1, suff =  1;
	
	for(int i = 0; i < n; i++){
		
	    if(pre == 0) {
			pre = 1;
		}
	    if(suff == 0){
			suff = 1;
		}
	    pre = pre * arr[i];
		suff = suff * arr[n-i-1];
		maxi = max(maxi, max(pre, suff));
	}
	
	return maxi;
}
TC -> O(N)
SC -> O(1)
