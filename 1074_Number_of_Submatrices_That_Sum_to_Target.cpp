class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &v, int target)
    {

        int m = v.size();
        int n = v[0].size();

      // create prefix sum matrix of m+2 and n+2 size and initilize with 0
        vector<vector<int>> psum(m + 2, vector<int>(n + 2, 0)); 
      // calculate prefix sum of given matrix
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                psum[i][j] = v[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
            }
        }

      
        int count = 0;
        // Now , for each index check for all possibilities  of submatrices , if sum of matrix is equal to target then increase the count
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int row = i; row <= m; row++)
                {
                    for (int col = j; col <= n; col++)
                    {
                        int sum = 0;
                        sum += psum[row][col] - psum[row][j - 1] - psum[i - 1][col] + psum[i - 1][j - 1];
                        if (sum == target)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
        ;
    }
};
