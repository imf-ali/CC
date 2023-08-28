class Solution {
public:
    int find(vector<pair<int,int>> graph[],vector<bool> &vis,int k){
        vector<int> dis(vis.size(),INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            for(auto node : graph[it.second]){
                int vertex = node.first;
                int wt = node.second;
                if(it.first + wt < dis[vertex]){
                    dis[vertex] = it.first + wt;
                    pq.push({it.first + wt,vertex});
                }
            }
        }

        int maxi = -1;
        for(int i=1; i<dis.size(); i++)  {
            if(dis[i]==INT_MAX)    {
                return -1;
            }
            maxi = max(dis[i],maxi);
        }
        return maxi;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        vector<bool> vis(n+1,false);
        for(auto it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        return find(graph,vis,k);
    }
};
