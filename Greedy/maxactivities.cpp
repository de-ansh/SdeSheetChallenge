#include<bits/stdc++.h>
using namespace std;
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n= start.size();
     vector<vector<int>> struc(n,vector<int>(2));
    for(int i=0;i<n;i++){
        struc[i][0] = finish[i];
        struc[i][1] = start[i];
    }
    sort(struc.begin(),struc.end());
    int lim = struc[0][0];
    int ans=1;
    
    for(int i=1;i<n;i++){
        if(struc[i][1]>=lim)
        {
            ans++;
            lim = struc[i][0];    
        }
    }
    return ans;
}