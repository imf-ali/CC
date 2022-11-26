#include <bits/stdc++.h> 

int find(vector<int> &rack,int ind,int lastind,vector<vector<int>> &dp){
    
    if(ind >= rack.size())
        return 0;
    
    if(dp[ind][lastind+1] != -1)
        return dp[ind][lastind+1];
    
    int x = -1;
    if(lastind == -1 || rack[ind] > rack[lastind]){
        x = rack[ind] + find(rack,ind + 1,ind,dp);
    }
    int y = find(rack,ind + 1,lastind,dp);
    
    return dp[ind][lastind+1] = max(x,y);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(rack.size() + 1,vector<int>(rack.size() + 2,-1));
	int ans = find(rack,0,-1,dp);
    
    return ans;
}
