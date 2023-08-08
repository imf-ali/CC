class Solution {
public:
    int par(int x, vector<int> &root){
        while(x != root[x]){
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }

    void unionFun(int x,int y,vector<int> &root){
        int parx = par(x,root);
        int pary = par(y,root);
        if(parx < pary){
            root[parx] = root[pary];
        }else{
            root[pary] = root[parx];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> root(maxi+1);
        for(int i=0;i<=maxi;i++)
            root[i] = i;
        for(auto it : nums){
            for(int i=2;i<=sqrt(it);i++){
                if(it%i == 0){
                   unionFun(it,i,root);
                   unionFun(it/i,i,root); 
                }
            }
        }
        map<int,int> mp;
        int res = 1;
        for(auto it : nums){
            res = max(res,++mp[par(it,root)]);
        }
        return res;
    }
};
