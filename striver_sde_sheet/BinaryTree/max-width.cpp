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
    void find(TreeNode* root,int level,int nodeNum, map<int,pair<int,int>> &mp, int &ans){

        if(!root)
            return;

        if(mp.find(level) != mp.end()){
            mp[level].first = max(mp[level].first, nodeNum);
            mp[level].second = min(mp[level].second, nodeNum);
        }
        else {
            mp[level] = { nodeNum, nodeNum };
        }
        
        ans = max(ans, mp[level].first - mp[level].second + 1);

        find(root->left, level + 1, 2LL *nodeNum + 1, mp, ans);
        find(root->right, level + 1, 2LL *nodeNum + 2, mp, ans);
    }
    int widthOfBinaryTree(TreeNode* root) {
        map<int,pair<int,int>> mp;
        int ans = 0;
        find(root,0,0,mp, ans);
        return ans;
    }
};
