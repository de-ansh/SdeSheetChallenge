#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == s) {
                
                vector<int>res;
                if(arr[i]<arr[j]){
                    res.push_back(arr[i]);
                    res.push_back(arr[j]);
                }  
               else{
                   res.push_back(arr[j]);
                   res.push_back(arr[i]);
      
               }
                ans.push_back(res);
            }
        }
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}