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
    TreeNode* lca(TreeNode *root,TreeNode *a,TreeNode *b){
        if(!root || root == a || root == b)
            return root;
        auto l = lca(root->left,a,b);
        auto r = lca(root->right,a,b);

        return l && r ? root : l && !r ? l : !l && r ? r : NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        
        queue<TreeNode*> q;
        vector<TreeNode*> vec;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vec.clear();
            while(n--){
                TreeNode *temp = q.front();
                q.pop();
                vec.push_back(temp);
                if(temp->left)  q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
        }

        TreeNode* ans = vec[0];
        for(auto it : vec){
            ans = lca(root,ans,it);
        }
        return ans;
    }
};
