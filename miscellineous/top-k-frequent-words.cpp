class Solution {
public:

    static bool comp(pair<int,string> a, pair<int,string> b){
        if(a.first > b.first)
            return true;
        if(a.first < b.first)
            return false;
        
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto it : words)
            mp[it]++;
        
        vector<pair<int,string>> vres;
        for(auto it : mp)
            vres.push_back({it.second,it.first});
        
        sort(vres.begin(),vres.end(),comp);

        vector<string> res;
        for(int i=0;i<k;i++)
            res.push_back(vres[i].second);
        
        return res;
    }
};
