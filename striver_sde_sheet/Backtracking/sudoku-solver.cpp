class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int row,int col,int nums){
        for(int i=0;i<9;i++){
            if(board[i][col] == nums + '1')
                return false;
        }

        for(int i=0;i<9;i++){
            if(board[row][i] == nums + '1')
                return false;
        }

        row = (row/3)*3;
        col = (col/3)*3;

        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] == nums + '1')
                    return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){

        if(col == 9){
            if(row == 8) return true;
            row++;
            col=0;
        }

        if(board[row][col] != '.'){
            return solve(board,row,col+1);
        }
        for(int nums=0;nums<9;nums++){
            if(isSafe(board,row,col,nums)){
                board[row][col] = '1' + nums;
                if(solve(board,row,col+1)){
                    return true;
                }
            }
            board[row][col]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board,0,0);
    }
};
