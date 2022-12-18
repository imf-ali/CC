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
    int find(TreeNode *root,bool &ans){

        if(root == NULL)
            return 0;

        int lh = find(root->left,ans);
        int rh = find(root->right,ans);

        if(abs(lh-rh) >= 2)
            ans = false;

        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        find(root,ans);

        return ans;
    }
};
