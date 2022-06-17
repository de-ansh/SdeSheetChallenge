#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long WaterTrapped=0;

    for(int i=0;i<n;i++){
        int j=i;
        long leftMax=0,rightMax=0;
        while(j>=0){
            leftMax=max(leftMax,arr[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMax=max(rightMax,arr[j]);
            j++;
        }
        WaterTrapped+= min(leftMax,rightMax)-arr[i];
    }
    return WaterTrapped;
}


long getTrappedWater(long *arr, int n){
    long *left = new long[n];

  long *right = new long[n];

   left[0] = arr[0];

   for(int i=1; i<n; i++){

       left[i] =  max(left[i-1], arr[i]);

   }

   right[n-1] = arr[n-1];

   for(int i=n-2; i>=0; i--){

 right[i] = max(right[i+1], arr[i]);

   }

   long ans=0;

   for(int i=0; i<n; i++){

       ans+=(min(left[i], right[i]) - arr[i]);

   }

   return ans;
}