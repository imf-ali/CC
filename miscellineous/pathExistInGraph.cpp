class Solution {
public:

    bool dfs(vector<vector<int>> &graph,int p,int destiny,vector<bool> &vis){
        if(p == destiny)
            return true;
        
        vis[p] = true;
        
        for(auto it : graph[p]){
            if(!vis[it] && dfs(graph,it,destiny,vis))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n,false);
        return dfs(graph,source,destination,vis);
    }
};
