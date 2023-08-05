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
    map<pair<int,int>,vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int start,int end){
        if(start > end)
            return {NULL};

        if(mp.find({start,end}) != mp.end())
            return mp[{start,end}];

        vector<TreeNode*> res;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> lt = solve(start,i-1);
            vector<TreeNode*> rt = solve(i+1,end);
            for(auto it : lt){
                for(auto it2 : rt){
                    TreeNode* root = new TreeNode(i);
                    root->left = it;
                    root->right = it2;
                    res.push_back(root);
                }
            }
        }
        return mp[{start,end}] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
