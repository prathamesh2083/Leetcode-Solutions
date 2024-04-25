class Solution {
public:
    int solve(string& s, int k, int i, char ch, vector<vector<int>>& dp) {
        if (i == s.length()) {

            return 0;
        }

        if (ch != '#' && dp[i][ch - 'a'] != -1) {
            return dp[i][ch - 'a'];
        }
        int ans = 0;
        if (ch == '#') {
            ans = max(ans, solve(s, k, i + 1, ch, dp));
            ans = max(ans, 1 + solve(s, k, i + 1, s[i], dp));
        } else {
            ans = max(ans, solve(s, k, i + 1, ch, dp));
            if (k >= abs(ch - s[i]))
                ans = max(ans, 1 + solve(s, k, i + 1, s[i], dp));
        }
        if (ch != '#')
            return dp[i][ch - 'a'] = ans;
        return ans;
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length() + 5, vector<int>(27, -1));
        return solve(s, k, 0, '#', dp);
    }
};
