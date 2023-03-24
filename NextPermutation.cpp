// brute force 
// step 1 -> Generate all permutations (using recursion)
// step 2 -> linear search the permutation 
// step 3 -> return the next index 

// better solution 
// it can only be used in c++ because we are using STL library in in
// using the next_permutation method

vector<int> nextGreaterPermutation(vector<int> &A) {
    next_permutation(A.begin(), A.end());
    return A;
}

// optimal solution

vector<int> nextGreaterPermutation(vector<int> &A) {
    int ind = -1;
    int n = A.size();
    for(int i = n-2; i >= 0; i--){
        if(A[i] < A[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(A.begin(), A.end());
        return A;
    }
    for(int i = n-1; i > ind; i--){
        if(A[i] > A[ind]){
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin()+ind+1, A.end());
    return A;
}
