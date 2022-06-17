#include<bits/stdc++.h>
using namespace std;
/*int getMedian(vector<vector<int>> &matrix)
{
    vector<int>ans;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    int n=ans.size();
    return ans[n/2];
}
*/

int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int getMedian(vector<vector<int>> &A)
{
    int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}