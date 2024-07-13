class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string dir) {
        int n = positions.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {positions[i], i, healths[i], dir[i] == 'L' ? 0 : 1};
        }
        sort(v.begin(), v.end());
      
        vector<int> remhealths(n, 0);
        stack<vector<int>> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                if (v[i][3] == 0) {
                    remhealths[v[i][1]] = v[i][2];

                } else {
                    st.push(v[i]);
                }
            } else if (v[i][3] == 1) {
                st.push(v[i]);
            } else {
                while (!st.empty()) {
                    if (v[i][2] == st.top()[2]) {
                        v[i][2] = 0;
                        st.pop();
                        break;
                    } else if (v[i][2] > st.top()[2]) {
                        v[i][2]--;
                        st.pop();
                    } else {
                        st.top()[2]--;
                        break;
                    }
                }
                if (st.empty()) {
                    if (v[i][2] != 0)
                        remhealths[v[i][1]] = v[i][2];
                }
            }
        }
        while (!st.empty()) {
            remhealths[st.top()[1]] = st.top()[2];
            st.pop();
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (remhealths[i] > 0) {
                ans.push_back(remhealths[i]);
            }
        }
        return ans;
    }
};
