class Solution {
public:
    bool find(vector<int> &nums,int sum, int curr,int ind,vector<vector<int>> &dp){
        if(curr*2 == sum)
            return true;
        
        if(dp[curr][ind] != -1)
            return dp[curr][ind];

        if(ind >= nums.size() || curr*2 > sum)
            return false;

        return dp[curr][ind] = find(nums,sum,curr,ind+1,dp) || find(nums,sum,curr+nums[ind],ind+1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        vector<vector<int>> dp(sum+1,vector<int>(nums.size()+1,-1));

        return find(nums,sum,0,0,dp);
    }
};
