class Solution {
public:
    int points[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int keys=0;
        pair<int,int> start;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '@')
                    start = {i,j};
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    keys++;
            }
        }
        int final_key_state = (1<<keys)-1;

        bool vis[m][n][final_key_state+1];
        memset(vis,false,sizeof(vis));

        queue<vector<int>> q;
        q.push({start.first, start.second, 0, 0});
        vis[start.first][start.second][0] = true;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            if(it[3] == final_key_state)
                return it[2];
            
            for(int i=0;i<4;i++){
                int newX = it[0] + points[i][0];
                int newY = it[1] + points[i][1];

                if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == '#') 
                    continue;
                
                int newKeyState = it[3];
                if(grid[newX][newY] >= 'a' && grid[newX][newY] <= 'f') {
                    newKeyState |= 1<<(grid[newX][newY] - 'a');
                    if(!vis[newX][newY][newKeyState]){
                        vis[newX][newY][newKeyState] = true;
                        q.push({newX,newY,it[2]+1,newKeyState});
                    }
                }
                
                if((grid[newX][newY] == '.' || grid[newX][newY] == '@') && !vis[newX][newY][newKeyState]){
                    vis[newX][newY][newKeyState] = true;
                    q.push({newX,newY,it[2]+1,newKeyState});
                }
                
                else if((grid[newX][newY] >= 'A' && grid[newX][newY] <= 'F') && !vis[newX][newY][newKeyState]){
                    if(1<<(grid[newX][newY] - 'A') & newKeyState){
                        vis[newX][newY][newKeyState] = true;
                        q.push({newX,newY,it[2]+1,newKeyState});
                    }
                }
            }
        }
        return -1;
    }
};
