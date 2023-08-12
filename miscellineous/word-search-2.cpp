struct Node{
    bool isWord;
    string word;
    vector<Node*> child;
    Node(){
        isWord = false;
        for(int i=0;i<26;i++)
            child.push_back(NULL);
    } 
};

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool isValid(int i, int j, vector<vector<char>> &board){
        return (i >= 0 && j >= 0 && i < board.size() && j < board[0].size());
    }

    void dfs(vector<vector<char>>& board,int i,int j,Node *root,vector<string> &res){

        if(root && root->isWord){
            res.push_back(root->word);
            root->isWord = false;
        }

        if(!isValid(i,j,board) || board[i][j] == '#' || !root)
            return;

        char letter = board[i][j];
        board[i][j] = '#';

        for(int k=0;k<4;k++){
            dfs(board,i+dir[k][0],j+dir[k][1],root->child[letter - 'a'],res);
        }
        board[i][j] = letter;
    }

    void build(string word,Node *root){
        Node *p = root;
        for(int i=0;i<word.size();i++){
            int c = word[i] - 'a';
            if(!p->child[c])
                p->child[c] = new Node();
            p=p->child[c];
        }
        p->isWord = true;
        p->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int m = board.size();
        int n = board[0].size();

        Node *root = new Node();
        for(auto it : words)
            build(it,root);

        vector<string> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root,res);
            }
        }
        return res;
    }
};
