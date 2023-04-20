// 1. brute force approach
// In brute force appraoch we will use three loops and try all the triplets that have the sum = 0 and we will use a SET data structure to store triplets to eliminate
// duplicates 
//code -> 
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                  vector<int> temp = { arr[i], arr[j], arr[k] };
                  sort(temp.begin(), temp.end());\
                  st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// 2. better solution 
// using hashing 
//we will run two loops for a and b and using hashing for c 
//a + b + c = 0 -> c = -(a+b)
//  code->
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        set<int> hashset;
        for(int j = i+1; j < n; j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = { arr[i], arr[j], third };
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;    
}


// 3. optimal approach
// uisng two pointer approach 
// first step -> sort the array 
// second step is to take 'a' as a constant 
// now the problem looks like 2 sum problem
// b+c = -a 
// now take two pointers lo and hi 
// a = arr[i] lo = arr[i+1] hi = arr[n-1]

vector<vector<int>> triplet(int n, vector<int> &arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = { arr[i], arr[j], arr[k] };
                ans.push_back(temp);
                j++; 
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

