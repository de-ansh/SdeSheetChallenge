int findMinimumCoins(int amount) 
{
    vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (amount>= coins[i]) {
      amount -= coins[i];
      ans.push_back(coins[i]);
    }
  }
    return ans.size();
}