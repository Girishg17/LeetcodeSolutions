/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* head;
    set<int>st;
    void solve(TreeNode* head,set<int>&st){
        if(head==NULL)return;
        if(head->left){
            st.insert(2*head->val+1);
            head->left->val=2*head->val+1;
            solve(head->left,st);
        }
        if(head->right){
            st.insert(2*head->val+2);
            head->right->val=2*head->val+2;
            solve(head->right,st);
        }
    }
    FindElements(TreeNode* root) {
        head=root;
        root->val=0;
        st.insert(0);
        solve(head,st);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */