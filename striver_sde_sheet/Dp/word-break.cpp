class Solution {
public:

    bool find(string s,int ind, map<string,bool> &mp,vector<int> &dp){
        if(ind == s.size())
            return true;

        if(dp[ind] != -1)
            return dp[ind];
        
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp += s[i];
            if(mp.find(temp) != mp.end() && find(s,i+1,mp,dp))
                return dp[ind] = true;
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> mp;
        for(auto it : wordDict)
            mp[it] = true;
        vector<int> dp(s.size()+1, -1);
        
        return find(s,0,mp,dp);
    }
};
