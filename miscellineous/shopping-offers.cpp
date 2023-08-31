class Solution {
public:
    int find(vector<int>& price, vector<vector<int>>& special, vector<int> &needs,int ind, map<pair<int,vector<int>>,int> &mp){

        if(ind == special.size()){
            int temp = 0;
            for(int i=0;i<needs.size();i++){
                if(needs[i] > 0)
                    temp += needs[i]*price[i];
            }
            return mp[{ind,needs}] = temp;
        }

        if(mp.find({ind,needs}) != mp.end())
            return mp[{ind,needs}];
        int cost = INT_MAX;
        bool take = true;
        for(int i=0;i<special[ind].size()-1;i++){
            if(special[ind][i] > needs[i]){
                take = false;
                break;
            }
        }
        if(take){
            for(int i=0;i<special[ind].size()-1;i++){
                needs[i] -= special[ind][i];
            }
            cost = special[ind][special[ind].size()-1];
            cost += find(price,special,needs,ind,mp);
            for(int i=0;i<special[ind].size()-1;i++){
                needs[i] += special[ind][i];
            }
        }
        cost = min(cost,find(price,special,needs,ind+1,mp));
        return mp[{ind,needs}] = cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<pair<int,vector<int>>,int> mp;
        return find(price,special,needs,0,mp);
    }
};
