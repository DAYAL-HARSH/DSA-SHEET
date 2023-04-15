// brute force method 
// step 1 -> firstly sort the array 
// step 2 -> print arr[n-2] element 
// this approach fails when we have duplicate elements in an array so we use another method
// in this method we sort the array first and then we take two variables
// largest = arr[n-1] and secondLargest and then run a loop from the back (i = n-2; i >= 0; i--)
// now we compare arr[i] != largest if it is not then we store it in secondLargest and return it.
code -> 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int secondLargest;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int largest = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        if(arr[i] != largest){
            secondLargest = arr[i];
            break;
        }
    }
    cout<<secondLargest;
    return 0;
}
TC -> O(N logN)
SC -> O(1)

// Better Solution 
// In this approach we take two loops one for finding largest element and one for second largest element (*not nested loops)
// we take two variables largest and secondLargest(secondL)
// largest = arr[0] and secondLargest = INT_MIN;
code -> 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int secondLargest = INT_MIN;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int largest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    cout<<secondLargest;
    return 0;
}
TC -> O(N + N) -> O(2N)
SC -> O(1)
  
// Optimal solution
// By modifying the previous approach instead of using two loops we will use one loop and perform all the operations in it
// In this approach we take largest = arr[0] and secondLargest = -1;
// if arr[i] > largest then obviously we have to update our largest and secondLargest elements ( largest = arr[i] and secondLargest = largest)
// else if(arr[i] < largest && arr[i] > secondLargest) we update our largest and secondLargest elements
  
// code -> 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int secondLargest = -1;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int largest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    }
    cout<<secondLargest;
    return 0;
}

TC -> O(N)
SC -> O(1)
