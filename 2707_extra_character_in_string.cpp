class Solution
{
public:
    int solve(string &s, vector<string> &dict, int i, unordered_map<string, int> &mp, vector<int> &dp)
    {
        if (i >= s.length())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        string tmp = "";
        int cnt = INT_MAX;

        for (int j = i; j < s.length(); j++)
        {
            tmp += s[j];              // if tmp string is present in dictionary then find number of extra charcters in next string
            if (mp[tmp] == 1)
            {

                cnt = min(cnt, solve(s, dict, j + 1, mp, dp));
            }
        }

        cnt = min(cnt, 1 + solve(s, dict, i + 1, mp, dp)); // consider current character as extra character and then calculate extra character in next string

        return dp[i] = cnt;
    }
    int minExtraChar(string s, vector<string> &dict)
    {
        unordered_map<string, int> mp;
        // create map to identify whether string is in dictionary or not
        for (int i = 0; i < dict.size(); i++)
        {
            mp[dict[i]] = 1;
        }

        // in dp vector store minimum number of extra character from ith index 
        vector<int> dp(s.length(), -1);

        return solve(s, dict, 0, mp, dp);
    }
};
