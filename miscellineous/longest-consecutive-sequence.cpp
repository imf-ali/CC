class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)
            return n;

        sort(nums.begin(),nums.end());
        
        int maxi = 1;
        int count = 1;

        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] - nums[i-1] == 1){
                    count++;
                    maxi = max(maxi,count);
                }
                else count = 1;
            }
        }
        return maxi;
    }
};
