#include <bits/stdc++.h> 
using namespace std;
#include <vector>
/*
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==target)
                return true;
        }
    }
     return false;
}
*/


bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int low=0;
    if(!mat.size()) return false;
    int high=(m*n)-1;
    while(low<=high){
        int mid = (low + (high - low) / 2);
        if(mat[mid/n][mid%n]==target)
            return true;
        if(mat[mid/n][mid%n]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}