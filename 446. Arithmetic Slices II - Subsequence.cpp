typedef long long ll;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &v)
    {
        ll n = v.size();

        vector<unordered_map<ll, int>> dp(n);
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                dp[i][(ll)v[i] - v[j]]++;
            }
        }

        ll cnt = 0;

        for (ll i = 1; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                ll diff = (ll)v[i] - v[j];
                dp[i][diff] += dp[j][diff];
            }
        }

        for (ll i = n - 1; i > 1; i--)
        {
            for (ll j = i - 1; j >= 0; j--)
            {
                ll diff = (ll)v[i] - v[j];
                ll tmp = max((ll)dp[j][diff], (ll)0);

                cnt += tmp;
            }
        }

        return cnt;
    }
};
