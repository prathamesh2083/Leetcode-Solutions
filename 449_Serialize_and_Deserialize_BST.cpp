
class Codec
{
public:
    string tree;
    TreeNode *head = NULL;

    // funcion to create a new node and insert into bst
    void insert(int num)
    {
        TreeNode *tmp = new TreeNode;
        tmp->val = num;
        tmp->left = tmp->right = NULL;

        if (head == NULL)
        {
            head = tmp;
            return;
        }
        TreeNode *p = head, *q = NULL;
        while (p)
        {
            q = p;
            if (num < p->val)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (num < q->val)
        {
            q->left = tmp;
        }
        else
        {
            q->right = tmp;
        }
    }

    void preorder(TreeNode *p)
    {
        if (p)
        {
            string node = to_string(p->val);
            tree += node + "/";                // creating string of tree by taking preorder and seperating each node of bst by adding "/" between them
            preorder(p->left);
            preorder(p->right);
        }
    }

    string serialize(TreeNode *root)
    {

        preorder(root);
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string s)
    {

        for (int i = 0; i < s.length();)
        {
            string node = "";
            while (s[i] != '/')
            {
                node += s[i];
                i++;
            }
            int num = stoi(node); // from the tree string , find out values of nodes then insert into bst
            insert(num);
            i++;
        }
        return head;
    }
};
