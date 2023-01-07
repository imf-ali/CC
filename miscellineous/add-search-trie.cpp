struct Node{
    bool end;
    Node* child[26];
};

Node *getNode(){

    Node* root = new Node();

    root->end = false;
    for(int i=0;i<26;i++)
        root->child[i] = NULL;
    
    return root;
}

class WordDictionary {
public:

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *temp = root;
        for(int i=0;i<word.size();i++){
            int ind = word[i] - 'a';
            if(!temp->child[ind])
                temp->child[ind] = getNode();
            temp = temp->child[ind];
        }
        temp->end = true;
    }

    bool dfs(Node* root,string word,int ind){

        if(ind == word.size())
            return root->end;


        if(word[ind] == '.'){
            for(int i=0;i<26;i++){
                if(root->child[i] && dfs(root->child[i],word,ind+1))
                    return true;
            }
            return false;
        }

        int index = word[ind] - 'a';
        if(!root->child[index])
            return false;

        return dfs(root->child[index],word,ind+1);
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
