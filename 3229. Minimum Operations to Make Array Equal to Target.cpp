class Solution {
public:
    long long solve(vector<int>& tmp) {

        int n = tmp.size();
        for (int i = 0; i < n; i++) {
            tmp[i] = abs(tmp[i]);
        }
        long long count = 0;
        int bar = 0;
        for (int i = 0; i < n; i++) {
            if (bar < tmp[i]) {
                count += tmp[i] - bar;
                bar = tmp[i];
            } else if (tmp[i] < bar) {
                bar = tmp[i];
            }
        }
        return count;
    }
    long long minimumOperations(vector<int>& v, vector<int>& target) {
        long long cnt = 0;
        int n = v.size();
        vector<int> diff(n, 0);
        vector<int> tmp;

        for (int i = 0; i < n; i++) {
            diff[i] = target[i] - v[i];
        }
        int ind = 0;
        while (ind < n) {
            if (diff[ind] != 0) {
                tmp.push_back(diff[ind]);
                ind++;
                break;
            }
            ind++;
        }
        if (tmp.size()==0) {
            // all neutral
            return 0;
        }

        bool inc = false, dec = false, neu = false;
        if (tmp[0] < 0) {
            dec = true;
        } else {
            inc = true;
        }

        for (int i = ind; i < n; i++) {
            if (diff[i] == 0) {
                // neutral
                cnt += solve(tmp);
                tmp.clear();
            } else if (diff[i] > 0) {
                if (inc) {
                    tmp.push_back(diff[i]);

                } else {
                    cnt += solve(tmp);
                    tmp.clear();
                    tmp.push_back(diff[i]);
                    inc = true;
                    dec = false;
                }
            } else {
                if (dec) {
                    tmp.push_back(diff[i]);

                } else {
                    cnt += solve(tmp);
                    tmp.clear();
                    tmp.push_back(diff[i]);
                    inc = false;
                    dec = true;
                }
            }
        }
        if (tmp.size() != 0) {
            cnt += solve(tmp);
        }
        return cnt;
    }
};
