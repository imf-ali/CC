class Solution {
public:
    int find(vector<int> &prices,int ind,int opt,int limit,vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || limit == 0)
            return 0;

        if(limit == 0)
            return 0;

        if(dp[ind][opt][limit] != -1)
            return dp[ind][opt][limit];
        
        int profit = 0;
        if(!opt){
            profit = max(-prices[ind] + find(prices,ind+1,1,limit,dp), find(prices,ind+1,0,limit,dp));
        }else{
            profit = max(prices[ind] + find(prices,ind+1,0,limit-1,dp), find(prices,ind+1,1,limit,dp));
        }
        return dp[ind][opt][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (3,-1)));
        return find(prices,0,0,2,dp);
    }
};
