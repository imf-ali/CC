class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool isValid(vector<vector<int>> &grid,int i,int j){
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }

    bool isBorder(vector<vector<int>> &grid,int i,int j,int clr,vector<vector<bool>> &vis){
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
            return true;
        
        for(int k=0;k<4;k++){
            int newX = i + dir[k][0];
            int newY = j + dir[k][1];

            if(isValid(grid,newX,newY) && !vis[newX][newY] && grid[newX][newY] != clr)
                return true;
        }
        return false;
    }

    void find(vector<vector<int>> &grid,int i,int j,int clr,int color, vector<vector<bool>> &vis){

        vis[i][j] = true;

        if(isBorder(grid,i,j,clr,vis))
            grid[i][j] = color;

        for(int k=0;k<4;k++){
            int newX = i + dir[k][0];
            int newY = j + dir[k][1];

            if(isValid(grid,newX,newY) && !vis[newX][newY] && grid[newX][newY] == clr)
                find(grid,newX,newY,clr,color,vis);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int clr = grid[row][col];
        find(grid,row,col,clr,color,vis);
        return grid;
    }
};
