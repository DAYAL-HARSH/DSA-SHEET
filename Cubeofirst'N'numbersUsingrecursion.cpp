#include <iostream>
using namespace std;

int f(int n){
    if(n == 0){
        return 0;
    }
    return n*n*n+f(n-1);
    
}
int main() {
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
