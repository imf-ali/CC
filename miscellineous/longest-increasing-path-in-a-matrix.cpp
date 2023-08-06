class Solution {
public:

    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int find(vector<vector<int>> &matrix,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(!valid(i,j,m,n))
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;
        for(int k=0;k<4;k++){
            int newx = i + dir[k][0];
            int newy = j + dir[k][1];
            if(valid(newx,newy,m,n) && matrix[newx][newy] > matrix[i][j]){
                maxi = max(maxi,find(matrix,newx,newy,m,n,dp));
            }
        }
        return dp[i][j] = maxi + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == -1)
                    ans = max(ans,find(matrix,i,j,m,n,dp));
            }
        }
        return ans;
    }
};
