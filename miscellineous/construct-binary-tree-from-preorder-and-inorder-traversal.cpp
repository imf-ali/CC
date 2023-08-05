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
    map<int,int> mp;
    int index=0;
    TreeNode* build(vector<int> &preorder, vector<int> &inorder,int left,int right){
        if(left > right || index >= preorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        int ind = mp[preorder[index]];
        index++;
        root->left = build(preorder,inorder,left,ind-1);
        root->right = build(preorder,inorder,ind+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
