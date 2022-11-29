/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int>*,int>> q;
    map<int,vector<int>> mp;
    q.push({root,0});
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        mp[t.second].push_back(t.first->data);
        if(t.first->left){
            q.push({t.first->left,t.second-1});
        }
        if(t.first->right){
            q.push({t.first->right,t.second+1});
        }
    }
    
    vector<int> ans;
    for(auto it : mp){
        for(auto it2 : it.second)
            ans.push_back(it2);
    }
    return ans;
}
