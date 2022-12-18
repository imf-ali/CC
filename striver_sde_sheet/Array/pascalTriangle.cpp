class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        if(numRows == 1)
            return {{1}};
        
        if(numRows == 2)
            return {{1},{1,1}};

        ans[0] = {1};
        ans[1] = {1,1};

        for(int i=2;i<numRows;i++){
            ans[i].push_back(1);
            for(int j=0;j<i-1;j++){
                ans[i].push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }

        return ans;
    }
};
