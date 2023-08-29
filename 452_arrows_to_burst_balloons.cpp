class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end()); // sort by start index
        int cnt = 0;
        int n = v.size();
        int start = -1, end = -1;
        // create a space between start and end . if ballon is in this space then adjust the space according to ballons's indices
        // if ballon is not in space then increment count and assign start and end to ballons indices
        for (int i = 0; i < n; i++)
        {
            if (start == -1)
            {
                start = v[i][0];
                end = v[i][1];
            }
            else
            {
                if (v[i][0] > end)  
                {
                    cnt++;         // current balloon is not in space ,so increment and assign its indices to start and end
                    start = v[i][0];
                    end = v[i][1];
                }
                else
                {
                    start = v[i][0];    // current balloon is in space
                    end = min(end, v[i][1]);
                }
            }
        }

        return cnt + 1;
    }
};
