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
class Solution {
public:
    int find(TreeNode* root,int &ans){
        if(root == NULL)
            return 0;
        
        int lh = find(root->left,ans);
        int rh = find(root->right,ans);

        ans = max(ans,lh + rh + root->val);
        int val = max(lh,rh) + root->val;

        return val < 0 ? 0 : val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        find(root,ans);

        return ans;
    }
};
