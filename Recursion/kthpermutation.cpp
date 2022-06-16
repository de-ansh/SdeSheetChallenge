#include<bits/stdc++.h>
void solve(string &s, int index, vector<string> &res){
    if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
}
string kthPermutation(int n, int k) {
    // Write your code here.
    string s;
    vector<string> res;
    for(int i=1;i<=n;i++){
        s.push_back(i+'0');
    }
    solve(s,0,res);
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
}
