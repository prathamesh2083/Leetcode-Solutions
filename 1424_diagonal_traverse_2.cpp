class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &v)
    {

        int m = v.size();
        map<int, vector<int>> mp; // store numbers from each diagonal

        for (int i = 0; i < m; i++)
        {
            int row = i;
            for (int j = 0; j < v[i].size(); j++)
            {
                mp[row + j].push_back(v[i][j]);
            }
        }

        vector<int> diagonal;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            for (int i = it->second.size() - 1; i >= 0; i--) // as we are storing numbers in reverse , push numbers in map mp in reverse order in diagonal vector
            {
                diagonal.push_back(it->second[i]);
            }
        }
        return diagonal;
    }
};

