class Solution {
public:
    int lcs(string text1, string text2,int i,int j,vector<vector<int>> &dp){

        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int x = 0;
        if(text1[i] == text2[j])
            x = lcs(text1,text2,i+1,j+1,dp) + 1;
        
        int y = max(lcs(text1,text2,i+1,j,dp),lcs(text1,text2,i,j+1,dp));

        return dp[i][j] = max(x,y);
    }
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
                
                dp[i][j] = max(dp[i][j], max(dp[i-1][j],dp[i][j-1]));
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
};
