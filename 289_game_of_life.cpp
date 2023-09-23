class Solution
{
public:
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    void gameOfLife(vector<vector<int>> &board)
    {

        vector<vector<int>> v = board;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live = 0, dead = 0;
                for (int p = 0; p < 8; p++)
                {
                    int x = i + dx[p];
                    int y = j + dy[p];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (board[x][y] == 0)
                        {
                            dead++;
                        }
                        else
                            live++;
                    }
                }
                if (board[i][j] == 1)
                {
                    if (live < 2)
                    {
                        v[i][j] = 0;
                    }
                    else if (live == 2 || live == 3)
                    {
                        v[i][j] = 1;
                    }
                    else if (live >= 3)
                    {
                        v[i][j] = 0;
                    }
                }
                else
                {
                    if (live == 3)
                    {
                        v[i][j] = 1;
                    }
                }
            }
        }
        board = v;
    }
};
