class Solution {
public:
    int find(vector<int> &nums,int i,int j, int player){
        if(i > j || i == nums.size() || j == -1)   
            return 0;
        int res;
        if(player == 0)
            res = max(nums[i] + find(nums, i+1, j, 1), nums[j] + find(nums, i, j-1, 1));
        else 
            res = min(-nums[i] + find(nums, i+1, j, 0), -nums[j] + find(nums, i, j-1, 0));
        return res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return find(nums,0,n-1,0) >= 0;
    }
};
