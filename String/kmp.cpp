#include <bits/stdc++.h>
using namespace std;
vector<int>calPrefix(string pat, int n){
    int i=0,j=1;
    vector<int>prefix(n); 
    prefix[0]=0;
    while(j<n){
        if(pat[i]==pat[j]){
            prefix[j]=i+1;
            i++;
            j++;
        }
        else{
            if(i==0){
                prefix[j]=0;
                j++;
            }
            else{
                i=prefix[i-1];
            }
        }
    }
    return prefix;        
}
bool kmp(string txt, string pat, vector<int >&pre, int n, int m){
    int i=0,j=0;
    while(i<n){
        if(j==m)
            return true;
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        else{
            //txt pointer -i that will move forward
            //pat pointer -j will move back to pre[j-1]
            if(j!=0){
                j=pre[j-1];
            }
            else{
                i++;
            }
        }
        if(j==m)
            return true;
    }
    return false;
}
bool findPattern(string p, string s)
{
    int n=s.size();
    int m= p.size();
    vector<int>prefix=calPrefix(p,m);
    if(kmp(s,p,prefix,n,m)){
        return true;
    }
    else
        return false;
}