// there are two ways of doing this question 1. parameterised way 2. functional way

// 1. parameterised way

#include <iostream>
using namespace std;

void f(int i, int sum){
    if(i < 1){
        cout<<sum<<endl;
        return;
    }
    f(i-1,sum+i);
    
}
int main() {
    int n;
    cin>>n;
    f(n,0);
    return 0;
}

// 2. functional way
// in funcional way we are printing inside the main funciton.

#include <iostream>
using namespace std;

int f(int n){
    if(n == 0){
        return 0;
    }
    return n+f(n-1);
    
}
int main() {
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
