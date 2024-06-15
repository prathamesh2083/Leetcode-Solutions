class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = capital.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end());
        int i = 0;
        priority_queue<int> maxcap;
        while (i < n && k) {
            while (i < n && v[i].first <= w) {
                maxcap.push(v[i].second);
                i++;
            }
            if (maxcap.empty()) {
                return w;
            }
            k--;
            w += maxcap.top();
            maxcap.pop();
        }
        while (k-- && !maxcap.empty()) {
            w += maxcap.top();
            maxcap.pop();
        }
        return w;
    }
};
