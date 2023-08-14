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
    TreeNode* find(TreeNode* root,int key){
        if(!root)   
            return NULL;
        
        if(key < root->val)
            root->left =  find(root->left,key);
        else if(key > root->val)
            root->right = find(root->right,key);
        else{
            if(!root->left && !root->right)
                return NULL;
            if(!root->left || !root->right){
                TreeNode *temp = root->left ? root->left : root->right;
                return temp;
            }
            TreeNode *temp1 = root->left, *temp2 = root->right;
            root=root->right;
            while(root->left)   
                root=root->left;
            root->left = temp1;
            return temp2;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return find(root,key);
    }
};
