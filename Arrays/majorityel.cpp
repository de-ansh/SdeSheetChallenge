#include <bits/stdc++.h> 
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    int n= arr.size();
   unordered_map < int, int > mp;
  vector < int > ans;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }

  return ans;

}