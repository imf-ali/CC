#include <bits/stdc++.h> 

void dfs(vector<vector<int> > &maze,int n,int i,int j,vector<vector<int>> &ans,vector<vector<bool>> &vis,vector<int>&temp){
    
    if(i<0 || i>=n || j<0 || j>=n || !maze[i][j] || vis[i][j])
        return;
    
    vis[i][j] = true;
    
    temp[i*n + j] = 1;
    
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        vis[i][j] = false;
        temp[i*n + j] = 0;
        return;
    }
    
    dfs(maze,n,i,j+1,ans,vis,temp);
    dfs(maze,n,i+1,j,ans,vis,temp);
    dfs(maze,n,i-1,j,ans,vis,temp);
    dfs(maze,n,i,j-1,ans,vis,temp);
    
    temp[i*n + j] = 0;
    
    vis[i][j] = false;
    
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    vector<int>temp(n*n,0);
    
//     for(auto it : temp)
//         cout<<it<<" ";
//     cout<<endl;
    
    dfs(maze,n,0,0,ans,vis,temp);
    return ans;
}
