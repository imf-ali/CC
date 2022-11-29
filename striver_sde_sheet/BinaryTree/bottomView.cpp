/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void find(BinaryTreeNode<int> * root,map<int,pair<int,int>> &mp,int ind,int level){
    if(!root)
        return;
    
    if(mp.find(ind) != mp.end() && mp[ind].second <= level)
        mp[ind] = {root->data,level};
    else if(mp.find(ind) == mp.end())
        mp[ind] = {root->data,level};
    
    find(root->left,mp,ind-1,level+1);
    find(root->right,mp,ind+1,level+1);
    
}
vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    map<int,pair<int,int>> mp;
    find(root,mp,0,0);
    for(auto it : mp)
        ans.push_back(it.second.first);
    
    return ans;
}

