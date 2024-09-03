typedef long long ll;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<set<int>> v(2*(1e5 + 10));
        int high = 0;
        int extra=1e5;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {

            for (int j = 0; j < nums[i].size(); j++) {
                high = max(high,extra + nums[i][j]);
                v[extra+nums[i][j]].insert(i);
            }
        }
       
        int len =extra+ 1e5 + 10;
        int start = 0;
        map<int, int> mp;
        int i = 0, j = 0;
        while (j <= high) {
            for (auto it : v[j]) {
                mp[it]++;
            }

            while (i <= j && mp.size() == n) {
               

                int tmplen = j - i + 1;
                if (tmplen < len) {
                    len = tmplen;
                    start = i;
                }

                for (auto it : v[i]) {
                    mp[it]--;
                    if (mp[it] == 0)
                        mp.erase(it);
                }
                i++;
            }
            j++;
        }

        return {start-extra, start + len - 1-extra};
    }
};
