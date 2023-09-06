
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = 0;
        ListNode *p = head, *prev;
        while (p)
        {
            n++; // find length of list
            p = p->next;
        }
        
        // first divide list into k groups of equal size
        // if there is remainder is not equal to 0  then increment size of first x groups by 1
        // x=remainder
        int len = n / k;
        int rem = n % k;
        if (len == 0)
        {
            rem = 0;
        }
        if (len == 0)
        {
            len = 1;
        }
        // if there are less or equal to k elements then add 1 element to each group ,if not possible then keep it empty
        vector<ListNode *> ans(k, NULL);
        // create vector to store to answer

        int tmplen = 0;
        p = head;
        for (int i = 0; i < k && p; i++)
        {   

           // we have to find k groups 

            ans[i] = p;
            tmplen = 0;
            int x = len;
            if (i < rem)
            {
                x++;
            }
            prev = p;
            
            while (p && tmplen != x)
            {
                prev = p;
                tmplen++;
                p = p->next;
            }

            prev->next = NULL;
        }
        return ans;
    }
};
