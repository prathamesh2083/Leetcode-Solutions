class Solution
{
public:
  using DP = tuple<int, int, int>;

  struct HashFunction
  {
    size_t operator()(const DP &state) const
    {
      auto [i, jump, status] = state;
      return hash<int>()(i) ^ hash<int>()(jump) ^ hash<int>()(status);
    }
  };

  int solve(int i, int jump, int status, int k, unordered_map<DP, int, HashFunction> &dp)
  {

    if (i > k + 1)
    {
      // return if i>k+1
      return 0;
    }

    DP state = {i, jump, status};
    if (dp.find(state) != dp.end())
    {
      return dp[state];
    }

    int ans = 0;

    if (i == k)
    {
      ans += 1;
    }

    ans += solve(i + (1 << jump), jump + 1, 1, k, dp);

    if (status == 1 && i > 0)
    {
      ans += solve(i - 1, jump, 0, k, dp);
    }

    dp[state] = ans;
    return ans;
  }

  int waysToReachStair(int k)
  {
    unordered_map<DP, int, HashFunction> dp;
    int i=1,jump=0,status=1;
    return solve(i, jump, status, k, dp);
  }
};
