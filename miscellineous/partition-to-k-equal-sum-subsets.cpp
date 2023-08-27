class Solution {
public:

    bool find(int state,vector<int> &nums,int sum, int cur,int k,vector<int> &dp){

        if(sum == cur){
            cur = 0;
            k--;
        }

        if(k == 0 && (state == (1<<nums.size())-1))
            return dp[state] = true;

        if(dp[state] != -1)
            return dp[state];

        for(int i=0;i<nums.size();i++){ 
            if(cur + nums[i] > sum || state & 1<<i)
                continue;
            if(find(state | (1<<i), nums, sum, cur + nums[i], k, dp)){
                return dp[state] = true;
            }
        }
        return dp[state] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        if(sum % k)
            return false;
        vector<int> dp(1<<nums.size(),-1);
        return find(0,nums,sum/k,0, k,dp);
    }
};
