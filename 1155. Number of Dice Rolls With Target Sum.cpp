class Solution
{
public:
  int mod = 1e9 + 7;
  int find(int n, int k, int target, vector<vector<int>> &dp)
  {

    if (n < 0)
    {
      return 0;
    }
    if (n == 0 && target == 0)
    {
      return 1;
    }
    if (dp[n][target] != -1)
    {
      return dp[n][target];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
      if (target - i < 0)
      {
        break;
      }
      ans = (ans + find(n - 1, k, target - i, dp)) % mod;
    }
    return dp[n][target] = ans;
  }
  int numRollsToTarget(int n, int k, int target)
  {
    vector<vector<int>> dp(n + 2, vector<int>(1010, -1));
    return find(n, k, target, dp);
  }
};
