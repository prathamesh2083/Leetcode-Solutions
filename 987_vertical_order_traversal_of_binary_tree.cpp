
class Solution
{
public:
    static bool cmp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
    {

        int row1 = p1.first.second;
        int row2 = p2.first.second;
        int val1 = p1.second;
        int val2 = p2.second;
        int col1 = p1.first.first;
        int col2 = p2.first.first;

        if (col1 < col2)
        {
            return true;  // if column of first node is less then no swap
        }
        else if (col1 > col2)
        {
            return false;  // if column of first node is more then  swap
        }
        else
        {   // if column of both nodes are equal


            if (row1 == row2)  // if rows are alsol equal then swap according to their values
            {
                if (val1 < val2)
                {               // if value of first node is less then no swap
                    return true;
                }
                else
                {
                    return false; // if value of first node is more then  swap
                }
            }
            else if(row1<row2){
                return true;
            }
            else{
                return false;
            }

            return false;
        }
        return true;
    }
    void solve(vector<pair<pair<int, int>, int>> &ans, int row, int col, TreeNode *p)
    {
        // in this function traverse to all nodes and store its index along with its value into ans vector
        ans.push_back({{col, row}, p->val});

        if (p->left)
        {
            solve(ans, row + 1, col - 1, p->left);
        }
        if (p->right)
        {
            solve(ans, row + 1, col + 1, p->right);
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> fans;
        vector<int> tmp;

        // ans{{col,row},value}
        vector<pair<pair<int, int>, int>> ans;
        solve(ans, 0, 0, root);


        // sort using comparator function
        sort(ans.begin(), ans.end(), cmp);


        for (int i = 0; i < ans.size(); i++)
        {
            int row = ans[i].first.second;
            int col = ans[i].first.first;
            int val = ans[i].second;
            
        }


        // add elements to fans vector according to their columns
        int col = ans[0].first.first;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].first.first == col)
            {
                tmp.push_back(ans[i].second);
            }
            else
            {
                fans.push_back(tmp);
                tmp.clear();
                tmp.push_back(ans[i].second);
                col = ans[i].first.first;
            }
        }

        if (tmp.size() != 0)
        {
            fans.push_back(tmp);
        }
        return fans;
    }
};
