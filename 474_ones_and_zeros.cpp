class Solution
{
    int ans;

public:
    int subset(vector<pair<int, int>> &v, int size, int i, int zero, int one, int m, int n, vector<vector<vector<int>>> &dp)
    {
        if (zero > m || one > n)
        {
            return -99999;
        }

        if (i >= size)
        {

            return 0;
        }
        if (dp[i][zero][one] != -1)
        {
            return dp[i][zero][one];
        }
        int ans = 0;
        // take string
        ans = max(ans, 1 + subset(v, size, i + 1, zero + v[i].first, one + v[i].second, m, n, dp));
        // not take string
        ans = max(ans, subset(v, size, i + 1, zero, one, m, n, dp));
        return dp[i][zero][one] = ans;
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        int size = strs.size();
        vector<pair<int, int>> v(size);
        // initilize 3d dp vector(size,m,n)
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        for (int i = 0; i < size; i++)
        {    // store count of zero and one at each index
            int zero = count(strs[i].begin(), strs[i].end(), '0');
            int one = count(strs[i].begin(), strs[i].end(), '1');
            v[i] = {zero, one};
        }

        return subset(v, size, 0, 0, 0, m, n, dp);
    }
};
