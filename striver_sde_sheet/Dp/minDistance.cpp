class Solution {
public:
    int find(string &word1, string &word2,int i,int j,vector<vector<int>> &dp){
        
        if(i >= word1.size())
            return word2.size() - j;

        if(j >= word2.size())
            return word1.size() - i;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = find(word1,word2,i+1,j+1,dp);
    
        int x = 1 + find(word1,word2,i+1,j,dp); // delete
        int y = 1 + find(word1,word2,i,j+1,dp); // insert
        int z = 1 + find(word1,word2,i+1,j+1,dp); // replace
        
        return dp[i][j] = min(x,min(y,z));
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int ans = find(word1,word2,0,0,dp);
        return ans;
    }
};
