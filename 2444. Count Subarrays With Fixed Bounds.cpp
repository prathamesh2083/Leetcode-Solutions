class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {

        // 2 2 2 3 4 5 3 5 = 8
        int n = v.size();

        long long ans = 0;
        int firstmn = -1, firstmx = -1;
        int lastind = -1;
        for (int i = n - 1; i >= 0; i--) {

            if (v[i] >= minK && v[i] <= maxK) {
                if (lastind == -1)
                    lastind = i;
                if (v[i] == minK) {
                    firstmn = i;
                }
                if (v[i] == maxK) {
                    firstmx = i;
                }

            } else {

                firstmn = -1;
                firstmx = -1;
                lastind = -1;
            }
            if (!(lastind == -1 || firstmn == -1 || firstmx == -1)) {
                int index = max(firstmn, firstmx);
                ans += lastind - index + 1;
            }
        }

        return ans;
    }
};
