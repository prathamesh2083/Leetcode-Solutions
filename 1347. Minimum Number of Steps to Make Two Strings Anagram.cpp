class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        unordered_map<char,int>mp,mpt;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            mpt[t[i]]++;
        }
        int cnt=0;
        for(auto x=mpt.begin();x!=mpt.end();x++){
            if(x->second>mp[x->first]){
                cnt+=x->second-mp[x->first];
            }
        }
        return cnt;
    }
};
