/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool lca(TreeNode* root, TreeNode* p, vector<TreeNode*> &path){
        if(root == NULL)
            return false;

        path.push_back(root);

        if(root == p){
            return true;
        }

        if(lca(root->left,p,path) || lca(root->right,p,path)){
            return true;
        }

        path.pop_back();
        
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;

        lca(root,p,path1);
        lca(root,q,path2);

        int i=0;
        
        while(i < min(path1.size(),path2.size()) && path1[i] == path2[i]){
            i++;
        }

        return path1[--i]; 
    }
};
