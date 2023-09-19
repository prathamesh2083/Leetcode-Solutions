class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {

        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                row[i] = max(row[i], grid[i][j]); // finding building height from each row
            }
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                col[i] = max(col[i], grid[j][i]);// finding building height from each column
            }
        }

        int sum = 0, tsum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tsum += grid[i][j];
                sum += min(col[j], row[i]);  // increase height of current building upto minimum height between col[i] and row[i]
                
            }
        }

        return sum - tsum;
    }
};
