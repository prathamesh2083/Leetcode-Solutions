class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int mod = 1e9 + 7,count=-1,seats=0;
        
        int n = corridor.length();
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                seats++;
            }
        }

        if (seats == 2 )
        {
            return 1;
        }
        if (seats % 2 == 1)
        {
            return 0;
        }
        int seatcnt = 0,plantcnt=1;
        
        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                seatcnt++;
                if (seatcnt == 3)
                {
                    if (count == -1)
                    {
                        count = plantcnt%mod;
                    }
                    else
                    {
                        count = (1LL*count * plantcnt) % mod;
                    }
                    plantcnt = 1;
                    seatcnt = 1;
                }
            }
            if (seatcnt == 2 && corridor[i] == 'P')
            {
                plantcnt++;
            }
        }

        return max(0,count);
    }
};
