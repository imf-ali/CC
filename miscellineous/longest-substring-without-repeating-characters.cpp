class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int maxi=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] = j;
                maxi = max(maxi,j-i+1);
            } else {
                int curInd = mp[s[j]];
                while(i<=curInd){
                    mp.erase(s[i]);
                    i++;
                }
                mp[s[j]] = j;
            }
        }
        return maxi;
    }
};
