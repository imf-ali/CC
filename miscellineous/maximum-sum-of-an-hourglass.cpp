class Solution {
public:
    void precompute(vector<vector<long long>> &prefixsum,vector<vector<int>> &grid){
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                prefixsum[i][j] = prefixsum[i][j-1] + grid[i-1][j-1];
            }
        }
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                prefixsum[i][j] += prefixsum[i-1][j];
            }
        }
    }
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> prefixsum(m+1,vector<long long>(n+1,0));
        
        precompute(prefixsum,grid);

        int res = 0;
        for(int i=1;i+2<=grid.size();i++){
            for(int j=1;j+2<=grid[0].size();j++){
                int sum = prefixsum[i+2][j+2] - prefixsum[i-1][j+2] - prefixsum[i+2][j-1] + prefixsum[i-1][j-1];
                sum -= (grid[i][j-1] + grid[i][j+1]);
                res = max(res, sum);
            }
        }

        return res;
    }
};
