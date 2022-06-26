#include<bits/stdc++.h>
using namespace std;
int pref(char a){
if(a=='M') return 1000;
if(a=='D') return 500;
if(a=='C') return 100;
if(a=='L') return 50;
if(a=='X') return 10;
if(a=='V') return 5;
return 1;
}
int romanToInt(string s) {
int ans = 0;
for(int i=0;i<s.length();){
if(pref(s[i])>=pref(s[i+1])){
ans+=pref(s[i]);
i++;
}else{
ans += pref(s[i+1]) - pref(s[i]);
i+=2;
}
}
return ans;
}

