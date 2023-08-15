class Solution {
public:
    int find(vector<int> &prices,int ind,int opt,int k,vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || k <= 0)
            return 0;
        
        if(dp[ind][opt][k] != -1)
            return dp[ind][opt][k];

        int profit = 0;
        if(!opt){
            profit = max(-prices[ind] + find(prices,ind+1,1,k,dp), find(prices,ind+1,0,k,dp));
        }else {
            profit = max(prices[ind] + find(prices,ind+1,0,k-1,dp), find(prices,ind+1,1,k,dp));
        }
        return dp[ind][opt][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return find(prices,0,0,k,dp);
    }
};
