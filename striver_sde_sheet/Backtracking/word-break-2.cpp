class Solution {
public:

    void find(string s, int ind, string temp, vector<string> &res, map<string,bool> &mp){
        if(ind == s.size()){
            res.push_back(temp.substr(0,temp.size()-1));
            return;
        }

        string p="";
        for(int i=ind;i<s.size();i++){
            p += s[i];
            if(mp.find(p) != mp.end()){
                find(s,i+1,temp + p + " ",res, mp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> mp;
        for(auto it : wordDict)
            mp[it] = true;

        vector<string> res;
        find(s,0,"",res,mp);
        return res;
    }
};
