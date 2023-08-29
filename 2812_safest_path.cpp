class Solution
{
public:
    int safe_fact;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void thief_dist(vector<vector<int>> &grid, vector<vector<int>> &thief, int n)
    {
        // calculate minimum thief dist by using bfs
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            visited[i][j] = 1;
            for (int p = 0; p < 4; p++)
            {
                int x = i + dx[p];
                int y = j + dy[p];
                if (x < n && y < n && x >= 0 && y >= 0 && visited[x][y] == 0)
                {
                    thief[x][y] = dist + 1;

                    visited[x][y] = 1;
                    q.push({{x, y}, dist + 1});
                }
            }
        }
       
    }

    // apply dfs to find maximum safeness factor of all paths
    bool solve(vector<vector<int>> &thief, int n, int i, int j, vector<vector<int>> &visited, int fact, int dist,vector<vector<int>> &dp)
    {  

        if (i == n - 1 && j == n - 1)
        {   if(thief[i][j]<dist)
            return false;
            return true;
        }
        if (thief[i][j] < dist)
        {
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans = false;
        for (int p = 0; p < 4; p++)
        {
            int x = i + dx[p];
            int y = j + dy[p];
            if (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0)
            {
                visited[i][j] = 1;
                ans = ans || solve(thief, n, x, y, visited, min(fact, thief[x][y]), dist,dp);
                visited[i][j] = 0;
            }
        }
        return dp[i][j]=ans;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        safe_fact = 0; // initilize safeness factor=0

        vector<vector<int>> thief(n, vector<int>(n, 0)); // to store the minimum distance from thief

        vector<vector<int>> visited(n, vector<int>(n, 0));
        thief_dist(grid, thief, n);

        int low = 0, high = n - 1, mid;
        while (high - low > 1)
        {
            mid = (low + high) / 2;
            vector<vector<int>> dp(n, vector<int>(n, -1));
            if (solve(thief, n, 0, 0, visited, thief[0][0], mid,dp))
            {
                low = mid;
            }
            else
            {
                high = mid ;
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if (solve(thief, n, 0, 0, visited, thief[0][0], high,dp))
        {
            return high;
        }
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        if (solve(thief, n, 0, 0, visited, thief[0][0], low,dp1))
        {
            return low;
        }
        return 0;
    }
};
