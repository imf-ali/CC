/************************************************************

    Following is the TreeNode class structure:

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
void find(TreeNode<int> *root, map<int,pair<int,int>> &mp,int ind,int level){
    if(!root)
        return;
    
    if((mp.find(ind) == mp.end()) || (mp.find(ind) != mp.end() && mp[ind].second >= level))
        mp[ind] = {root->val,level};
    find(root->left,mp,ind-1,level+1);
    find(root->right,mp,ind+1,level+1);
}
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    map<int,pair<int,int>> mp;
    find(root,mp,0,0);
    
    for(auto it : mp)
        ans.push_back(it.second.first);
    
    return ans;
}
