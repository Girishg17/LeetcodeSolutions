#include <map>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void preorder(TreeNode* root, long long tsum, long long sum, map<long long, int>& mp, int& ans) {
        if (root == NULL) return;

      
        sum += root->val;

      
        if (mp.find(sum - tsum) != mp.end()) {
            ans += mp[sum - tsum];
        }

       
        mp[sum]++;
        
        
        preorder(root->left, tsum, sum, mp, ans);
        preorder(root->right, tsum, sum, mp, ans);

        
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> mp;
        mp[0] = 1; 
        long long sum = 0;
        int ans = 0;
        preorder(root, targetSum, sum, mp, ans);
        return ans;
    }
};
