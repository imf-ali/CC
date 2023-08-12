struct Trie{
    bool isWord;
    vector<Trie*> child;

    Trie(){
        isWord = false;
        for(int i=0;i<26;i++)
            child.push_back(NULL);
    }
};

class MagicDictionary {
public:
    Trie *root;
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it : dictionary){
            Trie *p = root;
            for(int i=0;i<it.size();i++){
                char c = it[i];
                if(!p->child[c - 'a'])
                    p->child[c - 'a'] = new Trie();
                p = p->child[c - 'a'];
            }
            p->isWord = true;
        }
    }

    bool searchHelp(Trie* root,string word){
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(root->child[c - 'a'])
                root = root->child[c - 'a'];
            else return false;
        }
        return root->isWord;
    }
    
    bool search(string searchWord) {
        int count = 0;
        Trie *p = root;
        for(int i=0;i<searchWord.size();i++){
            char c = searchWord[i];
            if(p->child[c - 'a']){
                Trie *temp = p;
                for(int j=0;j<26;j++){
                    if(j == c - 'a')    continue;
                    if(temp->child[j] && searchHelp(temp->child[j],searchWord.substr(i+1)))
                        return true;
                }
                p = p->child[c - 'a'];
            }
            else {
                Trie *temp = p;
                for(int j=0;j<26;j++){
                    if(temp->child[j] && searchHelp(temp->child[j],searchWord.substr(i+1)))
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
