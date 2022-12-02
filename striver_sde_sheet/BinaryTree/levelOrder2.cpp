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
    void traverse(TreeNode* root, map<int,vector<int>> &mp,int ind){
        if(root == NULL)
            return;

        mp[ind].push_back(root->val);
        traverse(root->left,mp,ind+1);
        traverse(root->right,mp,ind+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> mp;
        traverse(root,mp,0);

        vector<vector<int>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
