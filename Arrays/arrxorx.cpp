#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
long long c=0;
    for(int i=0;i<arr.size();i++){
        int current_xor = 0;
        for(int j=i;j<arr.size();j++){
            current_xor^=arr[j];
            if(current_xor==x) c++;
        }
    }
    return c;
}
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<arr.size();i++){
        cpx^=arr[i];
        if(cpx==x) c++;
        int h = cpx^x;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}