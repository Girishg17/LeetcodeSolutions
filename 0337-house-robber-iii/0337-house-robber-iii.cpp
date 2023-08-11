/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int dfs(TreeNode *root, int i, vector<unordered_map<TreeNode*, int>> &mp)
        {
            if (root == NULL) return 0;
            if(mp[i].find(root)!=mp[i].end())return mp[i][root];
            if (i == 1)
            {
                return mp[i][root]=max(root->val + dfs(root->left, 0, mp) + dfs(root->right, 0, mp), dfs(root->left, 1, mp) + dfs(root->right, 1, mp));
            }
            else
            {
                return mp[i][root]=dfs(root->left, 1,mp) + dfs(root->right, 1, mp);
            }
        }
    int rob(TreeNode *root)
    {
        vector<unordered_map<TreeNode*, int>> mp(2);
        return dfs(root, 1, mp);
    }
};