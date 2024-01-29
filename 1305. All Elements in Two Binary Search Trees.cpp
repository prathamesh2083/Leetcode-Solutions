
class Solution {
public:
    vector<int>v;
    void preorder(TreeNode * p){
        if(p){
            preorder(p->left);
            v.push_back(p->val);
            preorder(p->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        v.clear();
        preorder(root1);
        preorder(root2);
        sort(v.begin(),v.end());
        return v;
    }
};
