class Solution
{
public:
    vector<string> ans;
    bool isvalid(string s)
    {

        int n = s.length();
        if (s[n - 1] == '.')
        {
            return false;
        }
        
        string num;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {

                if (num.length() == 1)
                {
                    num = "";
                    continue;
                }
                if (num[0] == '0' || num.length() >= 4)
                {
                    return false;
                }
                int t = stoi(num);
                if (t > 255)
                {
                    return false;
                }
                num = "";
            }
            else
            {
                num.push_back(s[i]);
            }
        }
        if (num.length() == 1)
        {
            return true;
        }
        if (num[0] == '0' || num.length() >= 4)
        {
            return false;
        }
        int t = stoi(num);
        if (t > 255)
        {
            return false;
        }
        return true;
    }
    void find(string s, int n, int i, string tmp, int parts, int currlen)
    {
       
        if (i == n && parts == 3)
        {
            if (isvalid(tmp))
            {
                ans.push_back(tmp);
            }
            return;
        }
        if (i >= n)
        {
            return;
        }
        if (parts >= 4)
        {
            return;
        }
        if (currlen > 4)
        {
            return;
        }

        find(s, n, i + 1, tmp + s[i], parts, currlen + 1);
        find(s, n, i + 1, tmp + s[i] + ".", parts + 1, 0);
    }
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.length();
        string tmp = "";
        find(s, n, 0, tmp, 0, 0);
        
        return ans;
    }
};
