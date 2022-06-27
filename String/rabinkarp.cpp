#include <bits/stdc++.h>
using namespace std;
vector<int> stringMatch(string &str, string &pat) {
    vector<int>ans;
    
    if(pat.size()>str.size())
        return ans;
    unordered_map<char,int>m;
    
    for(int i='A';i<='Z';i++)
        m[i]= i;
    
    int k = pat.length();
    int hashstr=0;
    int hashpat=0;
    int a=0;
    while(a<k){
        hashstr+=m[str[a]];
        hashpat+= m[pat[a]];
        a++;
    }
    if(hashstr==hashpat){
        int i;
        for(i=0;i<k;i++){
            if(str[i]!=pat[i])
                break;
        }
        if(i==k)
        ans.push_back(0);
    }
    
    for(int i=k;i<str.size();i++){
        hashstr = hashstr+m[str[i]]-m[str[i-k]];
     
        if(hashstr==hashpat){
            int j;
            for(j=0;j<k;j++){
                if(str[j+i-k+1]!=pat[j])
                    break;
            }
            if(j==k)
            ans.push_back(i-k+1);
        }
       
        
    }
    
    return ans;
}
