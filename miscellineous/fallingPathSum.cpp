class Solution {
public:
    int find(vector<vector<int>>& matrix,int row, int col,vector<vector<int>> &dp){

        if((row == matrix.size()) || (col < 0) || (col == matrix[0].size()))
            return INT_MAX;

        if(dp[row][col] != -1)
            return dp[row][col]; 

        int x = find(matrix,row+1,col,dp);
        int y = find(matrix,row+1,col-1,dp);
        int z = find(matrix,row+1,col+1,dp);

        int p = min(x,min(y,z));

        return dp[row][col] = p == INT_MAX ? matrix[row][col] : matrix[row][col] + p;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
        int ans = INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            int temp=find(matrix,0,i,dp);
            ans = min(ans,temp);
        }
        return ans;
    }
};
