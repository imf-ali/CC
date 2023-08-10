class Solution {
public:
    bool possible(vector<vector<int>> &graph,int node, vector<int> &state){
        if(state[node] == 1)
            return false;
        if(state[node] == 2)
            return true;
        
        state[node] = 1;
        for(auto it : graph[node]){
            if(!possible(graph,it,state))
                return false;
        }
        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(possible(graph,i,state))
                res.push_back(i);
        }
        return res;
    }
};
