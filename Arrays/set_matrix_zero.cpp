#include <bits/stdc++.h> 
using namespace std;
//approach1
void setZeros(vector<vector<int>> &matrix)
{
	int rows=matrix.size(),cols=matrix[0].size();
    vector<int>arr1(rows,-1),arr2(cols,-1);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                arr1[i]=0;
                arr2[j]=0;
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr1[i]==0||arr2[j]==0 )
                matrix[i][j]=0;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]<=0)
                matrix[i][j]=0;
        }
    }
}

//approach 2
void setZeros(vector<vector<int>> &matrix)
{
    int col0=1,rows=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        if(matrix[i][0]==0) col0=0;
        for(int j=1;j<cols;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(int i=rows-1;i>=0;i--){
        for(int j=cols-1;j>=1;j--){
            if(matrix[i][0]==0|| matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        if(col0==0)
            matrix[i][0]=0;
    }
}