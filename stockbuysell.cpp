#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int maxpro=0;
	for(int i=0;i<prices.size();i++){
		for(int j=i+1;j<prices.size();j++){
			if(prices[j]>prices[i])
				maxpro=max(maxpro, prices[j]-prices[i]);
		}
	}
	return maxpro;
}