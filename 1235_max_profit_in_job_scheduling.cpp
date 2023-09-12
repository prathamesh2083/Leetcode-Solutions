class Solution
{
public:
    int solve(vector<int> &startTime, vector<int> &endTime, vector<int> &profit, int i, int prev, vector<int> &dp)
    {
        if (i >= profit.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int ans2 = 0, ans1 = 0;
        ans1 = solve(startTime, endTime, profit, i + 1, prev, dp);

        int nextindex = (lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin()); // finding next valid index

        ans2 = profit[i] + solve(startTime, endTime, profit, nextindex, i, dp);

       

        return dp[i]=max(ans1, ans2);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = endTime.size();
        vector<pair<int, pair<int, int>>> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {startTime[i], {endTime[i], profit[i]}};
        }
        sort(v.begin(), v.end());         // sorting all three vectors according to startTime vector
        for (int i = 0; i < n; i++)
        {
            startTime[i] = v[i].first;
            endTime[i] = v[i].second.first; 
            profit[i] = v[i].second.second;
        }
        vector<int> dp(n, -1);
        return solve(startTime, endTime, profit, 0, -1, dp);
    }
};
