class Solution {
public:
    pair<int, int> dfs(vector<vector<int>>& land, int i, int j) {

        if (i >= land.size() || j >= land[0].size() || land[i][j] == 0) {
            return {0, 0};
        }
        land[i][j] = 0;

        pair<int, int> p1 = dfs(land, i + 1, j), p2 = dfs(land, i, j + 1);
        return {max(i, p1.first), max(j, p2.second)};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    pair<int, int> p = dfs(land, i, j);
                    ans.push_back({i, j, p.first, p.second});
                }
            }
        }
        return ans;
    }
};
