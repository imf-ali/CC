#include <bits/stdc++.h> 

void find(string s,int start,map<string,bool> &mp,string temp,vector<string> &ans){
    
    if(start == s.size()){
        ans.push_back(temp);
        return;
    }
    
    string p = "";
    for(int i=start;i<s.size();i++){
        p += s[i];
        if(mp.find(p) != mp.end()){
            find(s,i+1,mp,temp+p+" ",ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string temp="";
    
    map<string,bool> mp;
    for(auto it : dictionary)
        mp[it] = true;
    
    find(s,0,mp,temp,ans);
    
    return ans;
}
