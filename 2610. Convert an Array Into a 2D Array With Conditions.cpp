class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(1){
            vector<int>tmp;
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second>0){
                    it->second--;
                    tmp.push_back(it->first);
                }
            }
            if(tmp.size()==0){
                break;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
