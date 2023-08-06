class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int i,int j,int m,int n){
        return (i>=0 && j>= 0 && i<m && j<n);
    }
    int find(vector<vector<int>> &grid,int i,int j,int m,int n){
        if(!valid(i,j,m,n))
            return 0;
        
        grid[i][j] = 0;
        
        int res = 1;
        for(int k=0;k<4;k++){
            int newX = i + dir[k][0];
            int newY = j + dir[k][1];
            if(valid(newX,newY,m,n) && (grid[newX][newY] == 1)){
                res += find(grid,newX,newY,m,n);
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    res = max(res,find(grid,i,j,m,n));
                }
            }
        }
        return res;
    }
};
