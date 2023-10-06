class Solution
{
public:
    bool isvalid(map<char, int> &req, map<char, int> &v)
    {
        for (auto it = req.begin(); it != req.end(); it++)
        {
            if (v[it->first] < it->second)       // this function it to check whether given string is present in current window or not
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int tlen = t.length();
        int slen = s.length();
        map<char, int> req, v;
        if (tlen > slen)
        {
            return "";
        }

        for (int i = 0; i < tlen; i++)
        {
            req[t[i]]++;
        }
        int minlen = INT_MAX;
        string ans = "";
        int i = 0, j = 0;
        int start=-1,end=-1;
        while (j < slen)
        {
            while (j < slen && !(isvalid(req, v)))
            {
                v[s[j]]++;  //  move j forward untill we cover of characters of given string
                j++;
            }

            if (j >= slen)
            {
                break;
            }

            if (isvalid(req, v))
            {
                if (j - i < minlen)
                {
                    minlen = j - i;
                    start=i;
                    end=minlen;
                   
                }
            }

            while (i < j && isvalid(req, v))
            {
                if (j - i < minlen)
                {
                    minlen = j - i;    // move i forward untill given string is present in our string
                    start=i;
                    end=minlen;  
                }

                v[s[i]]--;
                i++;
            }
        }
        while (i < j && isvalid(req, v))
        {
            if (j - i < minlen)
            {
                minlen = j - i;
                 start=i;
                    end=minlen;
            }
            v[s[i]]--;
            i++;
        }


        if(start==-1 || end==-1){   // if substring not found return ""
            return "";
        }
        ans=s.substr(start,end);
        return ans;
    }
};
