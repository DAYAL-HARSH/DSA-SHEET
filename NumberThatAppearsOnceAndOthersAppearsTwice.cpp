#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int xorr = 0;
	for(int i = 0; i < arr.size(); i++){
		xorr = xorr ^ arr[i];
	}	
	return xorr;
}
