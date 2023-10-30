
class Solution
{
public:
    long long minSum(vector<int> &v1, vector<int> &v2)
    {
        long long sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
        long long n1 = v1.size(), n2 = v2.size();
        for (int i = 0; i < n1; i++)
        {
            if (v1[i] == 0)
            {
                cnt1++;  // count of zero in v1
            }
            sum1 += v1[i];
        }
      
        for (int i = 0; i < n2; i++)
        {
            if (v2[i] == 0)
            {
                cnt2++;       // count of zero in v2
            }
            sum2 += v2[i];
        }
        long long cnt = cnt1 + cnt2;
        long long diff = abs(sum1 - sum2);

        if (cnt1 == 0 && cnt2 == 0)
        {
            if (sum1 == sum2)
            {
                return sum1;
            }
            return -1;
        }
        if (cnt1 == 0 && cnt2 != 0)
        {
            if (sum1 < sum2 + cnt2)
            {
                return -1;
            }
            return sum1;
        }
        if (cnt2 == 0 && cnt1 != 0)
        {
            if (sum2 < sum1 + cnt1)
            {
                return -1;
            }
            return sum2;
        }

        return (long long)max((long long)sum1 + cnt1, (long long)sum2 + cnt2);
    }
};
