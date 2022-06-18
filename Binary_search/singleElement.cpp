#include<bits/stdc++.h>
using namespace std;
int uniqueElement(vector<int> arr, int n)
{
    if(n==1)
       return arr[0];
    else if(arr[0] != arr[1])
       return arr[0];
    else if(arr[n-1] != arr[n-2])
       return arr[n-1];
	int low=0,high=n-1;
    while(low<=high){
        int mid = (low + high) / 2;
                
                if (mid % 2 == 0) {
                    if (arr[mid] != arr[mid + 1]) 
                    //Checking whether we are in right half

                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                } else {

                    //Checking whether we are in right half
                    if (arr[mid] == arr[mid + 1]) 
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                }
            }

            return arr[low];
}

