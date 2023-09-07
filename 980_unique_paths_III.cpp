class Solution
{
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int dfs(vector<vector<int>> &grid, int i, int j, int cnt)
    {

        if (grid[i][j] == 2)
        {
            if (cnt == 0) // if we are at end point and if we have covered all the empty cells i.e cnt==0 then return 1;
            {
                return 1;
            }
            return 0; // else return 0
        }

        if (grid[i][j] == -1)
        {
            return 0; // if obstacle return 0
        }

        if (grid[i][j] == 0)
        {
            cnt--; // if we are at a empty cell then decrease cnt by 1
        }

        int ans = 0;
        for (int p = 0; p < 4; p++)
        {
            int x = dx[p] + i; // traverse through four direction
            int y = dy[p] + j;
            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[i][j] != -1)
            {
                int val = grid[i][j];
                grid[i][j] = -1;
                ans += dfs(grid, x, y, cnt);
                grid[i][j] = val;
            }
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                { // find total count of empty cells in grid
                    cnt++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                {
                    return dfs(grid, i, j, cnt);
                }
            }
        }
        return 0;
    }
};
