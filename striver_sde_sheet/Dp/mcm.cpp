#include <bits/stdc++.h> 

int mcm(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    
    if(i+1>=j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mini = INT_MAX;
    for(int k=i+1;k<j;k++){
        int ans = mcm(arr,i,k,dp) + mcm(arr,k,j,dp) + arr[i]*arr[j]*arr[k];
        mini = min(mini,ans);
    }
    
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    int ans = mcm(arr,0,N-1,dp);
    return ans;
}
