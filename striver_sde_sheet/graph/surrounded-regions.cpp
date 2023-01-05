class Solution {
public:

    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>> &vis){
        int m = board.size();
        int n = board[0].size();

        if(i<0 || i>= m || j<0 || j>= n || vis[i][j] || board[i][j] != 'O')
            return;
        
        vis[i][j] = true;
        board[i][j] = '-';

        dfs(board,i-1,j,vis);
        dfs(board,i+1,j,vis);
        dfs(board,i,j-1,vis);
        dfs(board,i,j+1,vis);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            if(board[i][0] == 'O')
                dfs(board,i,0,vis);
        
        for(int j=1;j<n;j++)
            if(board[0][j] == 'O')
                dfs(board,0,j,vis);
        
        for(int i=1;i<m;i++)
            if(board[i][n-1] == 'O')
                dfs(board,i,n-1,vis);
            
        for(int j=1;j<n;j++)
            if(board[m-1][j] == 'O')
                dfs(board,m-1,j,vis);
        
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '-')
                    board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
