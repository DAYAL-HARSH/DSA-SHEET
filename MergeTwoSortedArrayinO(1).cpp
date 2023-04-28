1. brute force approach
In this approach we used another array to store the merge of these array in sorted order and after that we replaced the items
back to the original arrays 
code -> 
    #include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	long long arr[n+m];
	int left = 0;
	int right = 0;
	int index = 0;
	while(left < n && right < m){
		if(a[left] <= b[right]){
			arr[index] = a[left];
			left++;
			index++;
		}
		else{
			arr[index] = b[right];
			index++;
			right++;
		}
	}
	while(left < n){
		arr[index++] = a[left++];
	}
	while(right < m){
		arr[index++] = b[right++];
	}
	for(int i = 0; i < (n+m); i++){
		if(i < n){
			a[i] = arr[i];
		}
		else{
			b[i-n] = arr[i];
		}
	}
}
TC -> O(n+m) + O(n+m)
SC -> O(n+m)
    
    
2. first optimal approach 
In this approach we used two pointers one pointing at the last element of arr1(LEFT) (i.e which is the largest element in array 1)
and the second pointer points to the first element of array 2(RIGHT) (i.e which is the smallest element in array 2).
we compare the elements at both the pointers and if the element at RIGHT < LEFT we swap these two elements

code-> 
    
#include<vector>
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	int right = 0;
	int left = n-1;
	while(left >= 0 && right < m){
		if(a[left] > b[right]){
			swap(a[left],b[right]);
			left--;
			right++;
		}
		else{
			break;
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(),b.end());
}
TC -> O(min(n,m)) + O(nlogn) + O(mlogm)
SC -> O(1)
    
3. 2nd optimal approach
In this approach we used gap method, where gap = (size of array 1 + size of array 2)/2 
after calculating the value of gap we take two pointers and we keep these pointers gap apart
after that we compare the element at both the pointers if the element at first pointer is smaller than the other 
we swap them otherwise we increase the value of both the pointers
when left crosses right pointer we stop and again calculate the value of gap by dividing the previous value of gap/2

code-> 
#include<vector>

void SwapIfGreater(vector<long long> &a, vector<long long> &b, int ind1, int ind2){
	if(a[ind1] > b[ind2]){
		swap(a[ind1], b[ind2]);
	}
}


void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int len = n + m;
	int gap = len/2;
	while(gap > 0){
		int left = 0;
		int right = left + gap;
		while(right < len){
			
			if(left < n && right >= n){
				SwapIfGreater(a,b,left,right-n);
			}
			
			else if(left >= n){
				SwapIfGreater(b,b,left-n,right-n);
			}
			
			else{
				SwapIfGreater(a,a,left,right);	
			}
			left++;
			right++;
		}
		if(gap == 1) break;
		gap = (gap/2)+(gap%2);
	}
}

TC-> O(log(n+m)) + O(n+m)
SC-> O(1)
