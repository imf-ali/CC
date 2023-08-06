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
        if(parx < pary){
            root[pary] = root[parx];
        } 
        else {
            root[parx] = root[pary];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n);
        for(int i=0;i<n;i++)
            root[i] = i;

        vector<int> res;
        for(auto it : edges){
            if(par(it[0]-1,root) == par(it[1]-1,root)){
                res = {it[0],it[1]};
                return res;
            }else{
                unionDef(it[0]-1,it[1]-1,root);
            }
        }
        return {};
    }
};
