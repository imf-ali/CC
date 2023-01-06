class Solution {
public:

    bool topsort(vector<vector<int>> &graph,int u,vector<bool> &vis,vector<bool> &recur,vector<int> &ans){
        vis[u] = true;
        recur[u] = true;

        for(auto it : graph[u]){
            if(!vis[it] && !topsort(graph,it,vis,recur,ans))
                return false;
            else if(recur[it])
                return false;
        }

        recur[u] = false;
        ans.push_back(u);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        vector<bool> vis(numCourses,false);
        vector<bool> recur(numCourses, false);

        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i] && !topsort(graph,i,vis,recur,ans))
                return {};
        }

        return ans;
    }
};
