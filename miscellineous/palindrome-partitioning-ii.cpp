class Solution {
public:
    bool palindrome(string &s,int low,int high){
        while(low <= high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    int find(int ind, string &s, vector<int> &dp){
        if(ind == s.size())
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int mini = 10000;
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                if(dp[i+1] != -1)
                    mini = min(mini, 1 + dp[i+1]);
                else
                    mini = min(mini, 1 + find(i+1,s,dp));
            }
        }
        return dp[ind] = mini != 10000 ? mini : 0;
    }
    int minCut(string s) {
        vector<int> dp(s.size()+1, -1);
        return find(0,s,dp)-1;
    }
};
