#include<bits/stdc++.h>
void solve(int index, int n,string &s,vector<string> &ans){
     if(index==n){
         ans.push_back(s);
         return;
     }
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        solve(index + 1,n, s, ans);
        swap(s[index], s[i]);
      }
    
}
vector<string> findPermutations(string &s) {
    string temp="";
    vector<string>ans;
    solve(0, s.size(),s,ans);
    return ans;
}