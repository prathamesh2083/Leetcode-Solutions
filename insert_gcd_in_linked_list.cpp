
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *p = head;

        while (p && p->next)
        {
            int gd = (__gcd(p->val, p->next->val));  // find gcd 
             
            ListNode *tmp = new ListNode; // create new node
            tmp->val = gd;
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        return head;
    }
};
