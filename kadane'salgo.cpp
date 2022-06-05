#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long cursum=0;
	long long maxsum=0;
	for(int i=0;i<n;i++){
		cursum+=arr[i];
		maxsum=max(cursum,maxsum);
		if(cursum<=0)
			cursum=0;
	}
	return maxsum;
}