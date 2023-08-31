class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> indegree(n,0);
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        queue<int> q;

        for(auto it : richer){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0;i<n;i++){
            ans[i] = i;
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){

                if(quiet[ans[it]] > quiet[ans[node]])
                    ans[it]= ans[node];
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};
