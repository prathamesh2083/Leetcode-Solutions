class Solution
{
public:
    int minCost(string colors, vector<int> &time)
    {

        int n = colors.size();
        int i = 1;
        int ans = 0;

        int mx = time[0], sum = time[0];

        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                mx = max(time[i], mx);
                sum += time[i];
            }
            else
            {
                ans += sum - mx;
                sum = time[i];
                mx = time[i];
            }
        }
        ans += sum - mx;
        return ans;
    }
};
