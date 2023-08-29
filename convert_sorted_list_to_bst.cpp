
class Solution
{
public:
    TreeNode *create(vector<int> &v, int low, int high)
    {
        if (high < low)
        {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode *tmp = new TreeNode;
        tmp->val = v[mid];

        tmp->left = create(v, low, mid - 1); // assign left subtree
        tmp->right = create(v, mid + 1, high); // assign right subtree
        return tmp;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        TreeNode *tree_head = create(v, 0, n - 1);
        return tree_head;
    }
};
