class Solution {
public:

    bool valid(string s,vector<string>& words, unordered_map<string,int> mp){
        int n=words.size();
        int k=words[0].size();

        int count=0;
        string temp;
        for(int i=0;i<s.size();i+=k){
            temp = s.substr(i,k);
            if(mp[temp]){
                count++;
                mp[temp]--;
            } else return false; 
        }
        return count == n;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        int n = words.size();
        int k = words[0].size();
        for(string word : words)
            mp[word]++;
        
        vector<int> res;
        for(int i=0;i<s.size() - k * n + 1; i++){
            if(valid(s.substr(i,k*n),words,mp))
                res.push_back(i);
        }
        return res;
    }
};
