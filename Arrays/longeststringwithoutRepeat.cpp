#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char,int> mp;

int l=0;

int r=0;

int ans=0;

int n=input.length();

while(r<n)

{

 if(mp.find(input[r])!=mp.end())

  l=max(mp[input[r]]+1,l);

 mp[input[r]]=r;

 ans=max(ans,r-l+1);

 r++;

}

return ans;
}