class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
	vector<vector<int>> graph(n);
        vector<int>indegree(n,0);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1)
                q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int sz = q.size();
            res.clear();
            while(sz--){
                int node = q.front();
                q.pop();
                res.push_back(node);
                for(auto it : graph[node]){
                    if(--indegree[it] == 1)
                        q.push(it);
                }
            }
        }
        return res;
    }
};
