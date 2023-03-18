// brute force 
for(int i = 0; i < n; i++){
  int count = 0;
  for(int j = 0; j < n; j++){
    if(arr[j] == arr[i]){
      count++;
    }
  }
  if(count > n/2) return arr[i];
  
  // better solution
 
#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
	map<int, int> mpp;
	for(int i = 0; i < v.size(); i++){
		mpp[v[i]]++;
	}
	for(auto it : mpp){
		if(it.second > v.size()/2){
			return it.first;
		}
	}
	return -1;
}
  
// optimal solution
// using Moore's voting Algorithm 
  
int majorityElement(vector<int> v) {
	int cnt = 0;
    int ele;
    for(int i = 0; i < v.size(); i++){
        if(cnt == 0){
            cnt = 1;
            ele = v[i];
        }
        else if (v[i] == ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i]  == ele) cnt1++;
    }
    if(cnt1 > (v.size() / 2)){
        return ele;
    }
    return -1;
}
