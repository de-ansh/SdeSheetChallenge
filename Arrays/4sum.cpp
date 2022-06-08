#include <bits/stdc++.h> 
vector<vector<int>>twosum(vector<int>&nums,int target,int start){
        vector<vector<int>>res;
        int lo=start,hi=nums.size()-1;
        while(lo<hi){
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }
        return res;
    }
    vector<vector<int>> ksum(vector<int> &nums,int target,int start,int k){
        vector<vector<int>>res;
        if(start==nums.size()) return res;
        int avg_val=target/k;
        if(nums[start]>avg_val || avg_val>nums.back()) return res;
        if(k==2)
            return twosum(nums,target,start);
        for(int i=start;i<nums.size();i++){
            if(i==start || nums[i-1]!=nums[i]){
                for (vector<int>& subset : ksum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
        return res;
    }
string fourSum(vector<int> arr, int target, int n) {
     sort(arr.begin(),arr.end());
     vector<vector<int>>ans=ksum(arr,target,0,4);
     if(!ans.empty())
         return "Yes";
    else
        return "No";
}
