Brute Force approach
In this approach we took two variables missing = -1 and repeating = -1 
then we run two nested loop and keep an cnt = 0 inside the first loop to keep track of missing and repeating number
if cnt == 2 then it is the repeating number 
if cnt == 0 then it is the missing number 

code-> 
  vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int repeating = -1;
    int missing = -1;
    for(int i = 1; i <= a.size(); i++){
        int cnt = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] == i){
                cnt++;
            }
        }
        if(cnt == 2) repeating = i;
        if(cnt == 0) missing = i;
        if(missing != -1 && repeating != -1) break;
    }
    return {repeating, missing};
}
TC->O(N^2)
SC->O(1)

Better Solution
In this approach we used hashing by taking an hash array of size N+1 because it will include all the indexes that comes in the range of 1 to N
code -> 
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    int hash[n+1] = {0};
    for(int i = 0; i < n; i++){
        hash[a[i]]++;
    }
    int repeating = -1;
    int missing = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        if(hash[i] == 0) missing = i;
        if(missing != -1 && repeating != -1){
            break;
        }
    }
    return { repeating, missing };
}
TC->O(2N)
SC->O(N)

Optimal Approach 1 
In thsi approach we used simple mathmatics we took x as repeating number and y as missing number 
so we have two unknown variable we need atleast two equations to find out the value of x and y
so we calcculated sum of all the digits in the array - sum of all the digits from 1 to n this gives use the first equation 
x-y = -4
to find out the second equation we used the square of these numbers 
and find out the other equation 
x+y = -24
  
code-> 
  vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n = a.size();
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S = 0, S2 = 0;
    
    for(int i = 0; i < n; i++){
        S += a[i];
        S2 += a[i]*a[i];
    }

    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return { (int)x, (int)y };
}
TC->O(N)
SC->O(1)

Optimal approach 2 
using XOR method 
code-> 
  
