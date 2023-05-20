class Solution {
public:

    pair<bool,double> dfs(map<string,vector<pair<string,double>>> &graph, string a,string b,map<string,bool> &vis){
        if(a == b)
            return {true, 1};

        vis[a] = true;
        
        for(auto it : graph[a]){
            if(!vis[it.first]){
                auto p = dfs(graph,it.first,b,vis);
                if(p.first) {
                    vis[a] = false;
                    return {true, p.second * it.second};
                }
            }
        }

        vis[a] = false;
        return {false, -1};
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].push_back({equations[i][1],(double) values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/(double)values[i]});
        }

        vector<double> res;
        map<string,bool> vis;
        for(int i=0;i<queries.size();i++){
            if(graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end())
                res.push_back(-1);
            else res.push_back(dfs(graph,queries[i][0],queries[i][1],vis).second);
        }

        return res;
    }
};
