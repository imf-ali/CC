class Solution {
public:
    int find(vector<vector<int>> &dp,int i,int j,int m,int n){
    
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = find(dp,i+1,j,m,n) + find(dp,i,j+1,m,n);
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int>> graph(m,vector<int>(n,-1));
        return find(graph,0,0,m,n);
    }
};
