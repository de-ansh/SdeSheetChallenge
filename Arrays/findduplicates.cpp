//1st Approach
#include <bits/stdc++.h> 
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            return arr[i];
    }
    return -1;
}
//Anopther approach
int finddup(int arr[], int n){
	int slow = arr[0];
  int fast = arr[0];
  do {
    slow = arr[slow];
    fast = arr[arr[fast]];
  } while (slow != fast);
  fast = arr[0];
  while (slow != fast) {
    slow = arr[slow];
    fast = arr[fast];
  }
  return slow;
}