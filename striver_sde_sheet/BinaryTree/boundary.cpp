#include<bits/stdc++.h>
void getLeft(TreeNode<int>* root, vector<int> &left){
    
    if(!root || (!root->left && !root->right))
        return;
    
    left.push_back(root->data);
    
    if(root->left)
        getLeft(root->left,left);
    else
        getLeft(root->right,left);
}
void getRight(TreeNode<int>* root, vector<int> &right){
    if(!root || (!root->left && !root->right))
        return;
    
    right.push_back(root->data);
    
    if(root->right)
        getRight(root->right,right);
    else
        getRight(root->left,right);
}
void getLeaf(TreeNode<int>* root, vector<int> &leaf){
    if(root == NULL)
        return;
    if(!root->left && !root->right){
         leaf.push_back(root->data);
         return;
    }
    
    getLeaf(root->left,leaf);
    getLeaf(root->right,leaf);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    
    if(!root)
        return {};
    vector<int> lt,rt,leaf;
    getLeft(root->left,lt);
    getRight(root->right,rt);
    getLeaf(root->left,leaf);
    getLeaf(root->right,leaf);
    
    vector<int> ans;
    ans.push_back(root->data);
    for(auto it : lt)
        ans.push_back(it);
    for(auto it : leaf)
        ans.push_back(it);
    reverse(rt.begin(),rt.end());
    for(auto it : rt)
        ans.push_back(it);
    
    return ans;
}
