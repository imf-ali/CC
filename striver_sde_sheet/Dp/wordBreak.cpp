#include <bits/stdc++.h> 
int find(string target,vector<string> &arr, int i,int n,vector<int> &dp){
    if(i == target.size())
        return 1;
    
    if(dp[i] != -1)
        return dp[i];
    
    for(auto it : arr){
        if(target.substr(i,it.size())==it && find(target,arr,i+it.size(),n,dp)){
            return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int> dp(target.size()+1,-1);
    return find(target,arr,0,n,dp) ? true : false;
}
