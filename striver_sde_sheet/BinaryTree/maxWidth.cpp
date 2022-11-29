/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void find(TreeNode<int> *root, map<int,int> &mp,int level,int &maxi){
    if(!root)
        return;
    
    mp[level]++;
    maxi = max(maxi,mp[level]);
    find(root->left,mp,level+1,maxi);
    find(root->right,mp,level+1,maxi);
}
int getMaxWidth(TreeNode<int> *root)
{
    int maxi = 0;
    map<int,int> mp;
    find(root,mp,0,maxi);
    
    return maxi;
}
