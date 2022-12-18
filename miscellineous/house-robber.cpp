class Solution {
public:
    int find(vector<int>& nums,int ind,vector<int> &dp){
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int x = find(nums,ind+1,dp);
        int y = nums[ind];
        for(int i=ind+2;i<nums.size();i++){
            y = max(y,find(nums,i,dp) + nums[ind]);
        }

        return dp[ind] = max(x,y);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans = find(nums,0,dp);
        return ans;
    }
};
