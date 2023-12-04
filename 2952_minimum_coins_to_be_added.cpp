class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {

        long long int sum = 0;
        long long int n = coins.size();
        long long int ans = 0;

        sort(coins.begin(), coins.end());
        for (long long int i = 0; i < n; i++)
        {

            if (coins[i] > sum + 1)
            {

                sum += sum + 1;

                ans++;
                if (sum < coins[i])
                {
                    i--;
                }
                else
                    sum += coins[i];
            }
            else
            {
                sum += coins[i];
            }
        }

        while (sum < target)
        {
            sum += sum + 1;
            ans++;
        }
        return ans;
    }
};
