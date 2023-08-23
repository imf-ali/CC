class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node *prev = NULL;
            while(n--){
                Node *temp = q.front();
                q.pop();
                if(prev){
                    prev->next = temp;
                }
                prev = temp;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};
