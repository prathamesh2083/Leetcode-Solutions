class Solution
{
public:
    int mod = 1e9 + 7;
    char ch[5] = {'a', 'e', 'i', 'o', 'u'}; // define array for all vowels

    int solve(int n, char last, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return 1;  
        }

        if (dp[n][last - 'a'] != -1)
        {
            return dp[n][last - 'a'];
        }

        int sum = 0;
        if (last == 'a')  // a if only followed by e
        {
            sum = (solve(n - 1, 'e', dp) + sum) % mod;
        }
        else if (last == 'e')
        {   // e is followed by a or i
            sum = (solve(n - 1, 'a', dp) + sum) % mod;
            sum = (solve(n - 1, 'i', dp) + sum) % mod;
        }
        else if (last == 'i')
        {   // i is not followed by i
            for (int i = 0; i < 5; i++)
            {
                if (ch[i] != 'i')
                    sum = (solve(n - 1, ch[i], dp) + sum) % mod;
            }
        }
        else if (last == 'o')
        {   // o is followed by u or i
            sum = (solve(n - 1, 'u', dp) + sum) % mod;
            sum = (solve(n - 1, 'i', dp) + sum) % mod;
        }
        else
        {   // u is followed by a
            sum = (solve(n - 1, 'a', dp) + sum) % mod;
        }

        return dp[n][last - 'a'] = sum;
    }
    int countVowelPermutation(int n)
    {
        int sum = 0;
        n--;
        // dp to store remaining length of string , previous character
        vector<vector<int>> dp(n + 1, vector<int>(26, -1));

        for(int i=0;i<5;i++){
        // start from every vowel
        sum = (sum + solve(n, ch[i], dp)) % mod;
        }
       
        return sum;
    }
};
