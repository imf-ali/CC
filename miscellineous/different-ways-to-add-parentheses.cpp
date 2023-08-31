class Solution {
public:
    vector<int> find(string &expression,int i,int j,vector<vector<vector<int>>> &dp){

        if(dp[i][j].size() != 0)
            return dp[i][j];

        if(j - i + 1 <=2 ){
            return dp[i][j] = { stoi(expression.substr(i, j - i + 1)) };
        }

        vector<int> res;
        for(int ind = i;ind<=j;ind++){
            char sign = expression[ind];
            if(sign == '+' || sign == '-' || sign == '*'){
                vector<int> left = find(expression,i,ind-1,dp);
                vector<int> right = find(expression,ind+1,j,dp);

                for(auto l : left){
                    for(auto r : right){
                        if(sign == '+')
                            res.push_back(l + r);
                        else if(sign == '-')
                            res.push_back(l - r);
                        else if(sign == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        return dp[i][j] = res;
    }
    vector<int> diffWaysToCompute(string expression) {
       int n = expression.size();
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
       return find(expression,0,n-1,dp); 
    }
};
