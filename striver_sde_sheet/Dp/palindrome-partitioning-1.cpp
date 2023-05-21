class Solution {
public:

    bool palindrome(string s,int low,int high){
        while(low <= high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    void find(int ind, string s, vector<string> &temp, vector<vector<string>> &res){
        if(ind == s.size()){
            res.push_back(temp);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                find(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;

        find(0,s,temp,res);
        return res;
    }
};
