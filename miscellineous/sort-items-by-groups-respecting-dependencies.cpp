class Solution {
public:
    vector<int> topSort(auto &adj,vector<int> &degree,int size){
        queue<int> q;
        for(int i=0;i<size;i++)
            if(degree[i] == 0)
                q.push(i);
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it : adj[node]){
                if(--degree[it] == 0)
                    q.push(it);
            }
        }
        for(int i=0; i<size; i++)
            if(degree[i]>0) return {};
        
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i] == -1)
                group[i] = m++;
        }
        vector<vector<int>> adjNode(n);
        vector<set<int>> adjGroup(m);
        vector<int> degreeNode(n,0), degreeGroup(m,0);

        for(int i=0;i<n;i++){
            int grp1 = group[i];
            for(auto it : beforeItems[i]){
                int grp2 = group[it];
                if(grp1 != grp2 && (adjGroup[grp2].count(grp1) == 0)){
                    adjGroup[grp2].insert(grp1);
                    degreeGroup[grp1]++;
                }
                adjNode[it].push_back(i);
                degreeNode[i]++;
            }
        }

        vector<int> sortGrp = topSort(adjGroup,degreeGroup,m);
        vector<int> sortNode = topSort(adjNode,degreeNode,n);

        vector<vector<int>> sortNodes(m);
        for(auto it : sortNode){
            sortNodes[group[it]].push_back(it);
        }

        vector<int> res;
        for(auto it : sortGrp){
            for(auto it2 : sortNodes[it])
                res.push_back(it2);
        }
        return res;
    }
};
