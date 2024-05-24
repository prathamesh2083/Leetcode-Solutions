class Solution {
public:
    int maxscore(vector<string>& words, int i, map<char, int>& mp,
                 unordered_map<char, int>& freq, vector<int>& score) {

        if (i == words.size()) {
            int sc = 0;

            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second <= freq[it->first]) {

                    sc += it->second * score[it->first - 'a'];
                } else {
                    return 0;
                }
            }

            return sc;
        }
        int ans1 = maxscore(words, i + 1, mp, freq, score);
        int ans2 = 0;
        for (int j = 0; j < words[i].length(); j++) {
            mp[words[i][j]]++;
        }
        ans2 = maxscore(words, i + 1, mp, freq, score);
        for (int j = 0; j < words[i].length(); j++) {
            mp[words[i][j]]--;
        }
        return max(ans1, ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        unordered_map<char, int> freq;
        for (int i = 0; i < letters.size(); i++) {
            freq[letters[i]]++;
        }

        map<char, int> mp;

        return maxscore(words, 0, mp, freq, score);
    }
};
