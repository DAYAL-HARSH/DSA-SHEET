// brute force approach
// taking two variables count = 0 and longest = 1, x = arr[i];
// now checking in the array by iterating if x+1 element exists in the array by using linear search
// if it is found then increase count by 1 and x by 1;
// take the maximum of longest and count to store the value of longestconsecutivesequence

bool LinearSearch(vector<int>&a,int num){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == num){
            return true;
        }
    }
    return false;
};
int longestSuccessiveElements(vector<int>&a) {
    int longest = 1, count = 0;
    int currcount = 0;
    for(int i = 0; i < a.size(); i++){
        int x = a[i];
        count = 1;
        while(LinearSearch(a,x+1) == true){
            x = x+1;
            count = count + 1;
        }
        longest = max(longest,count);
    }
    return longest;
}

// better solution 
// step 1 : sort the array
// step 2 : take three variables currentcount = 0 and LastSmaller = INT_MIN; (lastsmaller is the previous number in the sequence like we have 2 then the lastsmaller is 1)
// longestconsecutivesequence = 1 ( asssuming that the longest sequence is of length 1)
// now checking in the array if arr[i] - 1 == lastsmaller if it is then increase the count and store the arr[i] in the lastsmaller to save the previous element in the 
// sequence to lastsmaller
// otherwise we will check for arr[i] != lastsmaller if this is the condition then assign count = 1 and lastsmaller = arr[i];
// now calculate the longestconsecutviesequence by calculating the max between count and longestconsecutivesequence;

int longestSuccessiveElements(vector<int>&a) {
    if(a.size() == 0) return 0;
    sort(a.begin(), a.end());
    int longest = 1, count = 0, last_smaller = INT_MIN;
    for(int i = 0; i < a.size(); i++){
        if(a[i]-1 == last_smaller){
            count = count + 1;
            last_smaller = a[i];
        }
        else if(a[i] != last_smaller){
            count = 1;
            last_smaller = a[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

// optimal solution 
//step 1 -> put everyone into an unordered set 
//step 1 -> take an element then check if it is the staring point of a sequence by checking the element-1 is there in the 
//sequence or not

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    int longest = 1;
    unordered_set<int> st;
    if(n == 0) return 0;
    for(int i = 0; i < n; i++){
        st.insert(a[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
              x = x + 1;
              cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
