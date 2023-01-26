typedef pair<int,pair<int,int>> ppii;

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it : flights)
            graph[it[0]].push_back({it[1],it[2]});
        
        priority_queue<ppii, vector<ppii>, greater<ppii>>pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int stop = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;

            if(stop > k)
                continue;

            for(auto it : graph[node]){
                if(cost + it.second < dist[it.first]){
                    dist[it.first] = cost + it.second;
                    pq.push({stop + 1, {it.first, cost + it.second}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};
