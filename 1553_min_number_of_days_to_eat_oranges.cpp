class Solution
{
public:
    unordered_map<int, int> dp;
    // this function returns the number of days required to eat n oranges
    int days(int n)
    {
        if (n <= 0)
        {                 // if number of oranges is 0 return -1
            return -1;  
        }

        if (dp[n] != 0)
        {
            return dp[n];
        }

        int ans = INT_MAX;
        // for n oranges if n is check two conditions , divisible by 2 and divisible by 3
        
        ans = 1 + min((n % 2) + days(n / 2), (n % 3) + days(n / 3));
        return dp[n] = ans;
    }
    int minDays(int n)
    {

        return days(n);
    }
};
