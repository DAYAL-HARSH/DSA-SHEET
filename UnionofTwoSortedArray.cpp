1. Brute force method
using a set datastructure to store unique elements and also in sorted way
code->
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin>>n1;
    cin>>n2;
    int arr1[n1]; 
    int arr2[n2];
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>arr2[i];
    }
    set<int> st;
    for(int i = 0; i < n1; i++) {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++) {
        st.insert(arr2[i]);
    }
    int n = st.size();
    vector<int> union_1(n);
    int i = 0;
    for(auto it : st) {
        union_1[i++] = it;
    }
    for(int i = 0; i < n; i++) {
        cout<<union_1[i]<<" ";
    }
    return 0;
}
using a set datastructure to store unique elements and also in sorted way

TC-> O(n1 log n1) + O( n2 log n2) + O(n1 + n2)
SC-> O(n1 + n2)
  
  
2. Optimal approach

code-> 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin>>n1;
    cin>>n2;
    int arr1[n1]; 
    int arr2[n2];
    int i = 0, j = 0;
    for(int i = 0; i < n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>arr2[i];
    }
    vector<int> unionArr;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    for(int i = 0; i < unionArr.size(); i++) {
        cout<<unionArr[i]<<" ";
    }
    return 0;
}
