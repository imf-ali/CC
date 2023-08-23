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
    pair<int,int> find(TreeNode *root,int &res){
        if(!root){
            return {INT_MAX,0};
        }

        auto one = find(root->left,res);

        auto two = find(root->right,res);

        int newLen = 1;
        int cur = 0;
        if(one.first == root->val){
            newLen += one.second;
            cur = one.second;
        }
        if(two.first == root->val){
            newLen += two.second;
            cur = max(cur,two.second);
        }
        
        res = max(res,newLen);
        return {root->val,cur + 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 1;
        find(root,res);
        return res-1;
    }
};
