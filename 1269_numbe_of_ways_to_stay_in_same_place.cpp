class Solution
{
public:
    int mod;
    int solve(int steps, int arrlen, int i, vector<vector<int>> &dp)
    {
        if (i == -1 || i == arrlen)
        {
            return 0;
        }
        // if steps are over 
        if (steps == 0)
        {
            if (i == 0)
            {               // if we are at index 0 return 1
                return 1;
            }
            return 0;    // else return 0
        }


        if (dp[steps][i] != -1)
        {
            return dp[steps][i];  // return repeated calls
        }

        int ans = solve(steps - 1, arrlen, i, dp) % mod; // stay at same position
        ans = (ans + solve(steps - 1, arrlen, i - 1, dp)) % mod;  // move to left
        ans = (ans + solve(steps - 1, arrlen, i + 1, dp)) % mod;  // move to right
        return dp[steps][i] = ans;
    }
    int numWays(int steps, int arrlen)
    {
        mod = 1e9 + 7;
        vector<vector<int>> dp(steps + 1, vector<int>(502, -1)); // as max number of steps are 500 , we will use maximum 500 length of arrlen so create 2d dp array with (steps+1, 502)
        return solve(steps, arrlen, 0, dp);
    }
};
