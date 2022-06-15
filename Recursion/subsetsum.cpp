#include<bits/stdc++.h>
using namespace std;

void solve(int ind,int n, int sum, vector<int> & num, vector<int>& ans){
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    solve(ind+1,n,sum+num[ind],num,ans);
    solve(ind+1,n,sum,num,ans);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    solve(0,num.size(), 0,num,ans);
    sort(ans.begin(),ans.end());
    return ans;
}