#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>> &mat,vector<int> &color,int c,int v){
    for (int i = 0; i < mat.size(); i++)
        if (mat[v][i] && c == color[i])
            return false;
    return true;
}
bool dfs(vector<vector<int>> &mat,vector<int> &color,int m,int p){
    int n = mat.size();
    
    if(p == n)
        return true;
    
    for(int j=1;j<=m;j++){
        if(isSafe(mat,color,j,p)){
            color[p]=j;
            if(dfs(mat,color,m,p+1))
                return true;
        }
        color[p]=0;
    }
    
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int> color(n);
    for(int i=0;i<n;i++)
        color[i]=0;
    
    for(int i=0;i<n;i++){
        if(!color[i]){
            if(!dfs(mat,color,m,i))
                return "NO";
        }
    }
    
    return dfs(mat,color,m,0) ? "YES" : "NO";
}
