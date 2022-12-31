class Solution {
public:
    int find(vector<int> &prices,int curInd,int prevInd,vector<vector<int>> &dp){

        if(curInd >= prices.size())
            return 0;

        if(dp[curInd+1][prevInd+1] != -1)
            return dp[curInd+1][prevInd+1];
        
        int x=0,y=0;
        if(prevInd == -1){
            x = max(find(prices,curInd+1,curInd,dp),find(prices,curInd+1,-1,dp));
        }
        else{
            y =  max(prices[curInd] - prices[prevInd] + find(prices,curInd+2,-1,dp),find(prices,curInd+1,prevInd,dp));
        }

        return dp[curInd+1][prevInd+1] = max(x,y);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return find(prices,0,-1,dp);
    }
};
