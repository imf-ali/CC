class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int par,int col,vector<int> &color){
        color[par] = col;
        for(auto it : graph[par]){
            if(color[it] == col)
                return false;
            if((color[it] == -1) && !dfs(graph,it,1-col,color))
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(auto it : dislikes){
            graph[it[0]-1].push_back(it[1]-1);
            graph[it[1]-1].push_back(it[0]-1);
        }
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1 && !dfs(graph,i,1,color))
                return false;
        }
        return true;
    }
};
