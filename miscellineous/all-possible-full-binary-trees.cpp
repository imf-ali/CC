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

    int nodes;
    vector<TreeNode*> make(int n){

        if(n == 1)
            return {new TreeNode()};
        
        vector<TreeNode*> res;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftvc = make(i);
            vector<TreeNode*> rightvc = make(n-1-i);
            for(auto l : leftvc){
                for(auto r : rightvc){
                    TreeNode* root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n & 1)) return {};
        return make(n);
    }
};
