class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string>ans;
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        map<int,set<string>>st;
        for(auto &[str,freq]:mp){
           st[freq].insert(str);
        }
        for(auto it=st.rbegin();it!=st.rend();it++){
             
             for(auto it1=it->second.begin();it1!=it->second.end();it1++){
                ans.push_back(*it1);
                if(ans.size()==k){
                    return ans;
                }
             }
        }
        return ans;
    }
};
