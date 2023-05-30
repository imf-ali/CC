class Solution {
public:
    void find(vector<int> &candidates, int ind, vector<int> &temp,vector<vector<int>> &res, int target){

        if(target == 0){
            res.push_back(temp);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(i > ind && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            temp.push_back(candidates[i]);
            find(candidates,i + 1, temp, res, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        find(candidates, 0, temp, res, target);

        return res;
    }
};
