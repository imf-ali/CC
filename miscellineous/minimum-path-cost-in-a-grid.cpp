class Solution {
public:
    int find(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &moveCost,vector<vector<int>> &dp){
        if(row == grid.size()-1)
            return grid[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int ans = INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            ans = min(ans, moveCost[grid[row][col]][j] + grid[row][col] + find(grid,row+1,j,moveCost,dp));
        }
        return dp[row][col] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            ans = min(ans,find(grid,0,j,moveCost,dp));
        }
        return ans;
    }
};
