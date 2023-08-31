class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        } 

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        set<int> st[n];
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                st[it].insert(node);

                for(auto it2 : st[node])
                    st[it].insert(it2);

                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            for(auto it : st[i])
                res[i].push_back(it);
        }
        return res;
    }
};
