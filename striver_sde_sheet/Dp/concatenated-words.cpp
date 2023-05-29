class Solution {
public:

    bool find(string s, int ind, map<string,bool> &mp,  vector<int> &dp){
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1)
            return dp[ind];
        
        string temp = "";
        for(int i=ind;i<s.size();i++){
            temp += s[i];
            if(temp != s && mp[temp] && find(s,i + 1, mp, dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        map<string,bool> mp;
        for(auto it : words)
            mp[it] = true;
        
        vector<string> res;

        for(auto word : words){
            vector<int> dp(word.size() + 1, -1);
            if(find(word, 0, mp, dp)){
                res.push_back(word);
            }
        }
        return res;
    }
};
