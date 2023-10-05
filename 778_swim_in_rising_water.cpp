class Solution
{
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool solve(vector<vector<int>> &grid, int i, int j, int limit, int n, vector<vector<int>> &visited, vector<vector<int>> &dp)
    {

        if (i == n - 1 && j == n - 1)
        {
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        bool ans = false;
        for (int k = 0; k < 4; k++)
        {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] <= limit && visited[x][y] == 0)
            {
                visited[x][y] = 1;
                ans = ans || solve(grid, x, y, limit, n, visited, dp);
                visited[x][y] = 0;
            }
        }

        return dp[i][j] = ans;
    }

    int swimInWater(vector<vector<int>> &grid)
    {

        int maxi = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxi = max(maxi, grid[i][j]); // find the maximum elevation
            }
        }

        int low = grid[0][0], high = maxi, mid;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        // apply binary search to find minimum elevation
        while (high - low > 1)
        {
            mid = (low + high) / 2;
            vector<vector<int>> dp(n, vector<int>(n, -1));

            if (solve(grid, 0, 0, mid, n, visited, dp))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if (solve(grid, 0, 0, low, n, visited, dp))
        {
            return low;
        }
        return high;
    }
};
