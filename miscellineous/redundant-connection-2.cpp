class Solution {
public:
    int par(int x,vector<int> &root){
        while(root[x] != x){
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }

    void unionDef(int x,int y,vector<int> &root){
        int parx = par(x,root);
        int pary = par(y,root);

        root[pary] = root[parx];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n),indegree(n+1,-1);
        for(int i=0;i<n;i++){
            root[i] = i;
        }
        int bl1 = -1, bl2 = -1;
        for(int i=0;i<edges.size();i++){
            if(indegree[edges[i][1]] != -1){
                bl1 = i;
                bl2 = indegree[edges[i][1]];
                break;
            }
            indegree[edges[i][1]] = i;
        }
        for(int i=0;i<edges.size();i++){
            if(bl1 == i)
                continue;
            if(par(edges[i][0]-1,root) == par(edges[i][1]-1,root)){
                if(bl1 == -1)
                    return {edges[i][0],edges[i][1]};
                else
                    return {edges[bl2][0],edges[bl2][1]};
            } 
            else {
                unionDef(edges[i][0]-1,edges[i][1]-1,root);
            }
        }
        return {edges[bl1][0],edges[bl1][1]};
    }
};
