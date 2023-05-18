class Solution {
public:
    int find(vector<int> &nums,int ind,vector<int> &dp){
        if(ind >= nums.size()-1)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int mini = 100000;
        for(int j=1;j<=nums[ind];j++){
            mini = min(mini,1 + find(nums, ind + j,dp));
        }

        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return find(nums,0,dp);
    }
};
