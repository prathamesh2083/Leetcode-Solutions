class Solution
{
public:
    int find(map<int, vector<int>> &pre, int n, vector<int> &time, int node, vector<int> &dp)
    {

        if (pre[node].size() == 0)
        {
            return time[node - 1];
        }

        if (dp[node] != -1)
        {
            return dp[node];
        }

        int ans = 0;
        for (int j = 0; j < pre[node].size(); j++)
        {
            ans = max(ans, find(pre, n, time, pre[node][j], dp));
        }

        return dp[node] = ans + time[node - 1];
    }
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        map<int, vector<int>> pre;
        vector<int> dp(n + 1, -1);  // store number of months to complete ith course

        for (int i = 0; i < relations.size(); i++)
        {
            pre[relations[i][1]].push_back(relations[i][0]); // finding prerequisites of all courses
        } 

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            ans = max(ans, find(pre, n, time, i + 1, dp));
        }

        return ans;
    }
};
