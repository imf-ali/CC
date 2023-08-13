class Solution {
public:

    bool valid(vector<int> &nums,int i,int j){
        if(j - i == 1)
            return nums[i] == nums[j];
        if((nums[i] == nums[j]) && (nums[i+1] == nums[i]))
            return true;
        return ((nums[i+1] - nums[i] == 1) && (nums[j] - nums[j-1] == 1));
    }
    bool find(vector<int> &nums,int i,int j,vector<int> &dp){

        if(i >= j)
            return false;

        if(dp[i] != -1)
            return dp[i];

        if(j - i == 1 || j - i == 2){
            return dp[i] = valid(nums,i,j);
        }
        
        if(valid(nums,i,i+1) && find(nums,i+2,j,dp))
            return dp[i] = true;

        else if(valid(nums,i,i+2) && find(nums,i+3,j,dp))
            return dp[i] = true;
        
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return find(nums,0,nums.size()-1,dp);
    }
};
