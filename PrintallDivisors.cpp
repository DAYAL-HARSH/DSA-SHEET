// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    set<int> ls;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            ls.insert(i);
            if(n/i != 1){
                ls.insert(n/i); 
            }
        }
    }
    for(auto it : ls){
        cout<<it<<" ";
    }
    return 0;
}
