class Solution
{
public: 
    // function to find longest common subsequence
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int len = 0;
        if (s1[i] == s2[j])
        {
            len = max(len, 1 + lcs(s1, s2, i + 1, j + 1, dp));
        }
        else
        {
            len = max(len, lcs(s1, s2, i, j + 1, dp));
            len = max(len, lcs(s1, s2, i + 1, j, dp));
        }
        return dp[i][j] = len;
    }
    int minInsertions(string s)
    {
        // to make string palindrome , we have to find longest palindromic subsequence in given string
        // number of insertions= length of string - longest palindromic subsequence length
        // we can find longest palindromic subsequence by finding longest common subsequence between given string and reverse of given string
         
        int common = 0;
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return n - lcs(s, rev, 0, 0, dp);
    }
};
