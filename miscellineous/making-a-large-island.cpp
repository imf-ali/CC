class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int i,int j,int n){
        return (i>=0 && j>=0 && i<n && j<n);
    }

    vector<vector<int>> move(int i,int j,int n){
        vector<vector<int>> res;
        for(int k=0;k<4;k++){
            int newX = i + dir[k][0];
            int newY = j + dir[k][1];
            if(valid(newX,newY,n)){
                res.push_back({newX,newY});
            }
        }
        return res;
    }

    int dfs(int i,int j,vector<vector<int>> &grid,int color){
        grid[i][j] = color;
        int res=1;
        for(int k=0;k<4;k++){
            int newX = i+dir[k][0];
            int newY = j+dir[k][1];
            if(valid(newX,newY,grid.size()) && (grid[newX][newY] == 1)){
                res += dfs(newX,newY,grid,color);
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int color = 2;
        int res = 0;
        map<int,int> area;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    area[color] = dfs(i,j,grid,color);
                    res = max(res,area[color]);
                    color++;
                }
            }
        }

        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    int temp = 1;
                    for(auto it : move(i,j,n)){
                        int newX = it[0];
                        int newY = it[1];
                        int colorid = grid[newX][newY];
                        if(colorid && (st.find(colorid) == st.end())){
                            st.insert(colorid);
                            temp += area[colorid];
                        }
                    }
                    st.clear();
                    res = max(res,temp);
                }
            }
        }
        return res;
    }
};
