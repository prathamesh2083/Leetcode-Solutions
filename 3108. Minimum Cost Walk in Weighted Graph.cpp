const int N = 1e5 + 10;

int parent[N];
class Solution {

public:
    void make(int v) { parent[v] = v; }

    int find(int v) {
        if (parent[v] == v) {
            return v;
        }

        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b, int w, vector<int>& ands) {
        a = find(a);
        b = find(b);
        if (a < b) {
            parent[b] = a;
            ands[a] &= w;
            ands[a] &= ands[b];
        } else {
            parent[a] = b;
            ands[b] &= w;
            ands[b] &= ands[a];
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {

        vector<int> ans(query.size(), -1);
        vector<int> ands(1e5 + 10, INT_MAX);

        for (int i = 0; i < n; i++) {

            make(i);
        }

        for (int i = 0; i < edges.size(); i++) {

            Union(edges[i][1], edges[i][0], edges[i][2], ands);
        }

        for (int i = 0; i < query.size(); i++) {

            if (query[i][0] == query[i][1]) {
                ans[i] = 0;
                continue;
            }
            if (find(query[i][0]) != find(query[i][1])) {
                ans[i] = -1;

            } else {

                ans[i] = ands[find(min(query[i][0], query[i][1]))];
            }
        }
        return ans;
    }
};
