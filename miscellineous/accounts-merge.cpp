class Solution {
public:
    int find(int x, vector<int> &root){
        while(x != root[x]){
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }
    void unionDef(int x,int y,vector<int> &root){
        int parx = find(x,root);
        int pary = find(y,root);
        if(parx < pary)
            root[parx] = root[pary];
        else
            root[pary] = root[parx]; 
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string,int> mp;
        vector<int> root(n);
        map<int,vector<string>> res;
        for(int i=0;i<n;i++)
            root[i] = i;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    unionDef(i,mp[accounts[i][j]],root);
                }
                else mp[accounts[i][j]] = find(i,root);
            }
        }
        for(auto it : mp){
            int ind = find(it.second,root);
            res[ind].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(auto it : res){
            vector<string> temp = it.second;
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[it.first][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};
