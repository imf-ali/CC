/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void find(TreeNode<int> *root, vector<int> &ans,int level){
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);
    
    find(root->left,ans,level + 1);
    find(root->right,ans, level + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    find(root,ans,0);
    
    return ans;
}
