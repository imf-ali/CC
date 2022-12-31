class Solution {
public:

    int dfs(vector<vector<int>>& grid,pair<int,int> curr,pair<int,int> &end,int &toCover,vector<vector<bool>> &vis){

        int i = curr.first;
        int j = curr.second;
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1 || vis[i][j] == true){
            return 0;
        }

        if(toCover == 1 && i == end.first && j == end.second){
            return 1;
        }
        int ans = 0;
        toCover--;
        vis[i][j] = true;

        ans += dfs(grid,{i + 1, j},end,toCover,vis);
        ans += dfs(grid,{i - 1, j},end,toCover,vis);
        ans += dfs(grid,{i, j + 1},end,toCover,vis);
        ans += dfs(grid,{i, j - 1},end,toCover,vis);

        toCover++;
        vis[i][j] =false;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int toCover = m*n;
        int obs = 0;
        pair<int,int> start,end;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == -1)
                    obs++;
                else if(grid[i][j] == 1)
                    start = {i,j};
                else if(grid[i][j] == 2)
                    end = {i,j};
            }
        }

        toCover -= obs;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        return dfs(grid,start,end,toCover,vis);
    }
};
