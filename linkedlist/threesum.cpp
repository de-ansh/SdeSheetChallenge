/*#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	 vector< vector<int> > ans;

  
   for (int i = 0; i < n-2; i++){

      for (int j = i+1; j < n-1; j++){          

          for (int k = j+1; k < n; k++){

              vector<int> temp;

              if (arr[i] + arr[j] + arr[k] == K){

                temp.push_back(arr[i]);

                  temp.push_back(arr[j]);

                  temp.push_back(arr[k]);

                  sort(temp.begin(),temp.end());

                  if(find(ans.begin(),ans.end(),temp)==ans.end())

                  {

                      ans.push_back(temp);

                  }

              }

           }

       }

    }

   return ans;
}*/
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
  vector<vector<int>> ans;

   sort(arr.begin() , arr.end());

   int left , right ;

   for(int i = 0 ; i<n ; i++)

   {

       left = i+1 ;

       right = n-1;

       while(left<right)

       {

           if(arr[left]+arr[right]+arr[i] == K)

           {

                ans.push_back({arr[i], arr[left], arr[right]});

               int x = arr[left] ;

               int y = arr[right] ;

               //skipping same elements

               while(left<right && arr[left]==x){

                   left++ ;

               }

                  while(left<right && arr[right]==y){

                   right-- ;

               }

           }

           else if(arr[left]+arr[right]+arr[i] < K){

               left++;

           }

           else{

               right--;

           }

       }

       //skipping same ith element

        while(i+1<n && arr[i]==arr[i+1]){

           i++ ;

       }

   }

   return ans;
}