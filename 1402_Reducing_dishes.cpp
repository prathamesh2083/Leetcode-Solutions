class Solution
{
public:
    int solve(vector<int> &satisfaction, int i, int mul, vector<vector<int>> &dp)
    {
        if (i >= satisfaction.size())
        {
            return 0;
        }
        if (dp[i][mul] != -1)
        {
            return dp[i][mul];
        }
        // we have to choices , to take  or not take ith satisfaction 
        // if satisfaction is taken then add saticfaction score and increase mul by 1
        // if not then just find answer for (i+1)th satisfaction by starting with mul 1
        return dp[i][mul] = max((solve(satisfaction, i + 1, mul + 1, dp) + satisfaction[i] * mul), solve(satisfaction, i + 1, 1, dp));
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());// sort satisfaction vector

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(satisfaction, 0, 1, dp);
    }
};
