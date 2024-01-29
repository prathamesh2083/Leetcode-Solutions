
class Solution {
public:
    int findsum(TreeNode * p,TreeNode* parent ,TreeNode*pparent){
        if(p==NULL){
            return 0;
        }

        if(pparent && pparent->val%2==0){
        
         return p->val+findsum(p->left,p,parent)+findsum(p->right,p,parent);
        }
        else{
            return findsum(p->left,p,parent)+findsum(p->right,p,parent);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode * gparent=NULL;
        TreeNode * parent=NULL;
        return findsum(root,parent,gparent);
    }
};
