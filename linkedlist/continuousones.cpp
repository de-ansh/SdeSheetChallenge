int longestSubSeg(vector<int> &arr , int n, int k){
   int cnt0 = 0;
    int l = 0; 
    int maxLen = 0; 
  
    // r decides current ending point, i.e. the right pointer.
    for (int r = 0; r < n; r++) { 
        if (arr[r] == 0) {
            cnt0++; 
        }
  
        // If there are more 0's move left pointer towards current ending point. 
        while (cnt0 > k) { 
            if (arr[l] == 0) {
                cnt0--; 
            }

            l++; 
        } 
  
        maxLen = max(maxLen, r - l + 1); 
    }
    
    return maxLen; 
}
