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
    int diameter(TreeNode* root,int &ans){
        if(root == NULL)
            return 0;
        
        int lt = diameter(root->left,ans);
        int rt = diameter(root->right,ans);

        ans = max(ans, lt + rt);

        return 1 + max(lt,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root,ans);

        return ans;
    }
};
