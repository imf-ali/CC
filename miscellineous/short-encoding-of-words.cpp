struct Node{
    map<char,Node*> child;
};
 
class Solution {
public:
    void build(Node *root, string word,vector<pair<Node*,int>> &res){
        Node *p = root;
        for(int i=word.size()-1;i>=0;i--){
            int ind = word[i] - 'a';
            if(p->child.find(ind) == p->child.end())
                p->child[ind] = new Node();
            p=p->child[ind];
        }
        res.push_back({p,word.size()+1});
    }
    int minimumLengthEncoding(vector<string>& words) {

        set<string> st;
        for(auto it : words)
            st.insert(it);
        Node *root = new Node();
        vector<pair<Node*,int>> res;
        for(auto it : st)
            build(root,it,res);
        int ans = 0;
        for(auto it : res)
            if(it.first->child.size() == 0)
                ans += it.second;
        return ans;
    }
};
