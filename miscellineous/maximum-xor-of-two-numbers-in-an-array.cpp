struct Trie{
    int num;
    vector<Trie*> child;
    Trie(){
        for(int i=0;i<2;i++)
            child.push_back(NULL);
    }
};

class Solution {
public:
    Trie *root = new Trie();

    void insert(int n){
        cout<<n<<endl;
        Trie *p = root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i) & 1;
            if(!p->child[bit])
                p->child[bit] = new Trie();
            p = p->child[bit];
        }
        p->num = n;
    }

    int find(int n){
        Trie *p = root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i) & 1;
            if(p->child[1 - bit])
                p = p->child[1 - bit];
            else p = p->child[bit];
        }
        return (n ^ p->num);
    }
    int findMaximumXOR(vector<int>& nums) {
       for(auto it : nums){
           insert(it);
       } 
       int maxi = 0;
       for(auto it : nums){
           maxi = max(maxi , find(it));
       }
       return maxi;
    }
};
