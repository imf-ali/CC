class Solution {
public:

    bool check(vector<vector<int>> &graph,int curr,int x,vector<int> &color){
        color[curr] = x;

        for(auto it : graph[curr]){
            if((color[it] == x )|| (color[it] == -1 && !check(graph,it,1-x,color)))
                return false;
        } 
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1 && !check(graph,i,1,color))
                return false;
        }
        return true;
    }
};
