// i have seen this question in hackerrank sde intern coding with slight change
//and i have failed to solve this question
#include<bits/stdc++.h>
string writeAsYouSpeak(int n) 
{
	if(n==1){
        return "1";
    }    
    string s=writeAsYouSpeak(n-1);
    int cnt=0;
    string ans="";
    char ch=s[0];
    for(int i=0;i<s.length();i++){
        if(s[i]==ch){
            cnt++;
        }else{
            ans+=to_string(cnt)+ch;
            ch=s[i];
            cnt=1;
        }
    }
    ans+=to_string(cnt)+ch;
    return ans;
}

/*
string writeAsYouSpeak(int n) 
{
    // Write your code here.
    if(n==1)
        return "1";
    if(n==2)
        return "11";
        
        string ans="11";
        for(int i=3;i<=n;i++)
        {
            ans=ans+'$';
            
            string temp="";
            int count=1;
            for(int j=1;j<ans.size();j++)
            {
                if(ans[j]==ans[j-1])
                {
                    count++;
                }
                else if(ans[j]!=ans[j-1])
                {
                    temp=temp+to_string(count);
                    temp.push_back(ans[j-1]);
                    count=1;
                }
            }
            ans=temp;
        }
    return ans;
}
*/