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


void solve(string s,int k,string &ans,int fact)

{

   if(k==0)

   {

       ans.append(s);

       return;

   }

   

   ans.push_back(s[k/fact]);

   s.erase(s.begin()+k/fact);

   solve(s,k%fact,ans,fact/s.length());

}

 

string kthPermutation(int n, int k) {

   // Write your code here.

   string s="";

   int fact=1;

   for(int i=1;i<=n;i++)

   {

       s.append(to_string(i));

       fact*=i;

   }

   fact/=n;

   string ans="";

   solve(s,k-1,ans,fact);

   return ans;

}

 