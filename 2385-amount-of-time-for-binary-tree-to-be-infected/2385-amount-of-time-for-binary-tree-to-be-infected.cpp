class Solution {
public:
    void insert(TreeNode * root, unordered_map<int, vector<TreeNode*>>& mp, TreeNode * parent) {
        if (root == NULL) return;
        
        
        
        if (root->left != NULL) {
            mp[root->val].push_back(root->left);
            mp[root->left->val].push_back(root);
        }
        
        if (root->right != NULL) {
            mp[root->val].push_back(root->right);
            mp[root->right->val].push_back(root);
        }
        
        insert(root->left, mp, root);
        insert(root->right, mp, root);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<TreeNode*>> mp;
        TreeNode* temp = root;
        TreeNode* parent = NULL;
        
        insert(temp, mp, parent);
        
        int time = -1;
        queue<pair<int, int>> st;
        st.push({start, -1});
        
        while (!st.empty()) {
            int size = st.size();
            while (size--) {
                int node = st.front().first;
                int pa = st.front().second;
                st.pop();
                
                for (auto it : mp[node]) {
                    if (it->val != pa) {
                        st.push({it->val, node});
                    }
                }
            }
            time++;
        }
        return time;
    }
};