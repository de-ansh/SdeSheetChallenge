#include <bits/stdc++.h> 
using namespace std;
//1st aapraoch
/*
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int>freq(n+1,0);
    pair<int,int>ans;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=1;i<n+1;i++){

       if(freq[i]==0){

           ans.first = i;

       }

       if(freq[i]>1){

           ans.second = i;

       }

   }
    return ans;
}*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n){

int Xor = 0;

for(auto i : arr){

 Xor ^= i;

}

 

for(int i = 1; i <=n; i++){

 Xor ^= i;

}

 

int rsb = Xor & -Xor;

 

int x = 0;

int y = 0;

 

for(auto i: arr){

 if(i & rsb)

  x ^= i;

 else y ^= i;

}

 

for(int i = 1; i <= n; i++){

 if(i & rsb)

  x  ^= i;

 else y ^= i;

}

 

for(auto i : arr){

 if(i == x)

  return {y,x};

 else if(i == y)

  return {x,y};

 

}

 

}
