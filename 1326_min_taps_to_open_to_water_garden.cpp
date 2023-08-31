class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        n++;
        vector<vector<int>> v(n);
        // create intervals of range of taps
        for (int i = 0; i < n; i++)
        {
            v[i] = {(i - ranges[i]) < 0 ? 0 : (i - ranges[i]), i + ranges[i]};
        }
        // sort the interval
        sort(v.begin(), v.end());

        int cnt = 0;
        int start = 0, far = 0;// start from point 0
        for (int i = 0; i < n;)
        {

            while (i < n && v[i][0] <= start)
            {
                far = max(far, v[i][1]);   // find farest point from start point
                i++;
            }

            cnt++;

            if (far >= n - 1)  // if farest point is greater or equal than garden size return cnt
            {
                return cnt;
            }
            if (i == n)     // if all intervals are over and still garden is not over then return -1 i.e we cannot water whole garden
            {
                return -1;
            }
            if (v[i][0] > far) // if there is any point which cannot be watered then return -1
            {
                return -1;
            }

            start = far; // assign value of farest point to start
        }
        return cnt;
    }
};
