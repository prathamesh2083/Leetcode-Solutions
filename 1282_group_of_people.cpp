class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &v)
    {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;

        for (int i = 0; i < v.size(); i++)
        {
            mp[v[i]].push_back(i); 
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<int> tmp;
            int sz = it->first;
            for (int i = 0; i < it->second.size(); i++)
            {
                tmp.push_back(it->second[i]);
                if (tmp.size() == sz)   // if group of required size is formed then push it into final answer 
                {
                    ans.push_back(tmp);
                    tmp.clear(); // after pushing into answer vector clear the tmp vector
                }
            }
        }
        return ans;
    }
};
