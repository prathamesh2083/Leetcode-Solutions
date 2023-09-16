class Solution
{
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool min_effort(vector<vector<int>> &heights, int m, int n, int i, int j, int effort)
    {

        if (i == m - 1 && j == n - 1)
        {
            return true;
        }
        bool ans = false;
        for (int p = 0; p < 4; p++)
        {
            int x = i + dx[p];
            int y = j + dy[p];
            if (x >= 0 && y >= 0 && x < m && y < n && heights[x][y] != -1 && (abs(heights[i][j] - heights[x][y]) <= effort))
            {
                int tmp = heights[i][j];
                heights[i][j] = -1;

                ans = ans || min_effort(heights, m, n, x, y, effort);
                heights[i][j] = tmp;
            }
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        int low = 0, high = 1e6 + 10, mid;

        while (high - low > 1)
        {                                       // use binary search to and check by taking mid as maximum abs difference we are getting answer or not
           
            mid = (low + high) / 2;
            if (min_effort(heights, m, n, 0, 0, mid))
            {                                          // if anwer is true then move to left of search space 
                high = mid;
            }
            else
            {
                low = mid;                           // if answer is false then move to right of search space
            }
        }
        if (min_effort(heights, m, n, 0, 0, low))
        {
            return low;
        }

        return high;
    }
};
