#include <iostream>
using namespace std;

void f(int i, int n){
    if(i < 1){
        return;
    }
    f(i-1,n);
    cout<<i<<" ";
    
}
int main() {
    int n;
    cin>>n;
    f(n,n);
    return 0;
}
