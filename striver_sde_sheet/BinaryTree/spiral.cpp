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
    void dfs(TreeNode* root, map<int,vector<int>> &mp,int ind){
        if(root == NULL)
            return;
        mp[ind].push_back(root->val);

        dfs(root->left,mp,ind+1);
        dfs(root->right,mp,ind+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int,vector<int>> mp;
        dfs(root,mp,0);

        vector<vector<int>> ans;
        for(auto it : mp){
            if(it.first & 1)
                reverse(it.second.begin(),it.second.end());
            ans.push_back(it.second);
        }

        return ans;
    }
};
