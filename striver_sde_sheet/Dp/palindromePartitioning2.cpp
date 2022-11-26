#include <bits/stdc++.h> 

bool palindrome(string s){    
    int i=0;
    int j=s.size()-1;
    
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
int find(string str,int i,int j,vector<vector<int>> &dp){
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i==j)
        return dp[i][j] = 0;
    
    if(palindrome(str.substr(i,j-i+1)))
        return dp[i][j] = 0;
    
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int p = find(str,i,k,dp) + find(str,k+1,j,dp);
        mini = min(mini,p);
    }
    return dp[i][j] = mini+1;
}
int palindromePartitioning(string str) {
    vector<vector<int>> dp(str.size()+1,vector<int>(str.size()+1,-1));
    int n = str.size();
    int x = find(str,0,n-1,dp);
    
    return x;
}

