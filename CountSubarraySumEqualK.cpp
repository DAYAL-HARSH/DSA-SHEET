1. brute force ->
  In this approach we will create all the subarrays and compare it with k if it is equal to k then we will increase cnt by 1 and return cnt.
  code -> 
    for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
        sum = 0;
        for(k = i to j){
          sum = sum + arr[k];
        }
        if(sum == k){
          cnt++
        }
      }
    }
    return cnt;
TC -> O(N^3)
  SC -> O(1)

2. better approach
   In this approach we reduce one loop by adding the sum before without using third loop 
   code - >
     cnt = 0;
     for(int i = 0; i < n; i++){
       sum = 0;
       for(int j = i; j < n; j++){
         sum += arr[j];
       }
       if(sum == k){
         cnt++;
       }
     } 
     return cnt;
        
TC -> O(N^2)
  SC -> O(1)
 
 3. optimal approach 
 using presum
 code-> 
  int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}

TC -> O(N LOGN)
  SC-> O(N)
