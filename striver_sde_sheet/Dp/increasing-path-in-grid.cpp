class Solution {
public:

    int mod = 1000000007;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    bool valid(vector<vector<int>> &grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return false;
        return true;
    }

    int dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){

        if(dp[row][col] != -1)
            return dp[row][col];

        int ans=1;

        for(int i=0;i<4;i++){
            int x = row + dx[i];
            int y = col + dy[i];
            if(valid(grid,x,y) && grid[x][y] > grid[row][col])
                ans = (ans%mod + dfs(grid,x,y, dp)%mod)%mod;
        }

        return dp[row][col] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        long long res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res = (res%mod + dfs(grid,i,j,dp)%mod)%mod;
            }
        }
        return (int)res%mod;
    }
};
