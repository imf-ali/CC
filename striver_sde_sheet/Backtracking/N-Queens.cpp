class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){
        int i,j;
        for(j=0;j<col;j++){
            if(board[row][j] == 'Q')
                return false;
        }
        for(i=0;i<n;i++){
            if(board[i][col] == 'Q')
                return false;
        }
        for(i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(i=row,j=col;i<n && j>=0;i++,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void find(vector<string> &board,int col,int n,vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                find(board,col+1,n,ans);
            }
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]="";
            for(int j=0;j<n;j++)
                board[i] += '.';
        }
        vector<vector<string>> ans;
        find(board,0,n,ans);
        
        return ans;
    }
};
