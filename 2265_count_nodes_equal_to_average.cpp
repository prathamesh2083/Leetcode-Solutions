
class Solution
{
public:
    int ans;
    pair<int, int> sumcount(TreeNode *p)  // return pair of sum , count of nodes in subtree
    {

        if (p == NULL)
        {
            return {0, 0};
        }
        
        pair<int, int> p1 = sumcount(p->left), p2 = sumcount(p->right);
        int sum = p->val + p1.first + p2.first;
        int cnt = 1 + p1.second + p2.second;
        if (sum / cnt == p->val)
        {
            ans++;
        }
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode *root)
    {
        ans = 0;
        sumcount(root);
        return ans;
    }
};
