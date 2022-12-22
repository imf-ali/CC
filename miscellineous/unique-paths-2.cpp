class Solution {
public:
    int find(vector<vector<int>> &obstacleGrid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j])
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = find(obstacleGrid,i+1,j,m,n,dp) + find(obstacleGrid,i,j+1,m,n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return find(obstacleGrid,0,0,m,n,dp);
    }
};
