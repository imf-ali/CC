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
    void find(TreeNode* root,int row,int col, map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> &mp){

        if(!root)
            return;
        mp[col][row].push(root->val);
        find(root->left, row + 1, col - 1, mp);
        find(root->right, row + 1, col + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mp;
        find(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> temp;
            for(auto it2 : it.second){
                while(!it2.second.empty()){
                    temp.push_back(it2.second.top());
                    it2.second.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
