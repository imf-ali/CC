class Solution {
    bool possible(vector<int> &nums,int diff,int p){
        int count = 0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i+1] - nums[i] <= diff){
                i+=2;
                count++;
                if(count == p)
                    return true;
            } else {
                i++;
            }
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0)
            return 0;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums[nums.size()-1] - nums[0];

        while(left < right){
            int mid = (left + right)/2;
            if(possible(nums,mid,p)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
