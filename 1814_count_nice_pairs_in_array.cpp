class Solution
{
public:
    int countNicePairs(vector<int> &v)
    {
        int mod = 1e9 + 7;
        int n = v.size();

        for (int i = 0; i < n; i++)
        {
            string num = to_string(v[i]);
            reverse(num.begin(), num.end());   // reverse number and replace v[i] by v[i]-rev(v[i])
            int rev = stoi(num);
            v[i] -= rev;
        }

        sort(v.begin(), v.end());     // sort vector v

        int pairs = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                pairs = (((cnt) * 1LL * (cnt - 1) / 2) % mod + pairs) % mod; 
                cnt = 1;
            }
            else
            {
                cnt = (cnt + 1) % mod;
            }
        }
        pairs = (((cnt) * 1LL * (cnt - 1) / 2) % mod + pairs) % mod;

        return pairs;
    }
};
