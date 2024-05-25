class Solution {
public:
    unordered_map<string, int> dict;
    vector<string> ans;

    void check(string& s, string finalString, string curr, int i) {

        if (i == s.length()) {

            if (finalString != "" && curr == "") {
                finalString.pop_back();
                ans.push_back(finalString);
            }
            return;
        }

        curr += s[i];
        check(s, finalString, curr, i + 1);
        if (dict[curr]) {
            finalString += curr + " ";
            curr = "";
            check(s, finalString, curr, i + 1);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            dict[wordDict[i]] = 1;
        }
        string finalString = "", curr = "";

        check(s, finalString, curr, 0);
        return ans;
    }
};
