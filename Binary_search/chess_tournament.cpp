bool stall(vector<int> barn, int dist, int cows){

int c = 1, placed = 0;

for(int i=1; i<barn.size(); i++){

 if(barn[i] - barn[placed] >= dist){

  placed = i;  

  c++;

 }

}

if(c >= cows) return true;

else return false;

}

 

int chessTournament(vector<int> barn , int n ,  int c){

// Write your code here

   sort(barn.begin(), barn.end());

 

int low = 0, high = barn[n-1], res;

while(low <= high){

 int mid = (low+high)/2;

 if(stall(barn, mid, c)){

  res = mid;

  low = mid+1;

 }

 else {

  high = mid-1;

 }

}

   return res;

}