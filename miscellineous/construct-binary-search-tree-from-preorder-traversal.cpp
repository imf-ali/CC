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
    int ind = 0;
    TreeNode* build(vector<int> &preorder,vector<int> &inorder,int i,int j,map<int,int> &mp){
        if(ind >= preorder.size() || i > j)
            return NULL;

        TreeNode* root = new TreeNode(preorder[ind]);
        int index = mp[preorder[ind]];
        ind++;

        root->left = build(preorder,inorder,i,index-1,mp);
        root->right = build(preorder,inorder,index+1,j,mp);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return build(preorder,inorder,0,inorder.size(),mp);
    }
};
