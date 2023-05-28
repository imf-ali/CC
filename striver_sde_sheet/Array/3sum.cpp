class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        set<vector<int>> res;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int low = i+1, high = nums.size()-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0)
                    low++;
                else if(nums[i] + nums[low] + nums[high] > 0)
                    high--;
                else {
                    res.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }

        for(auto it : res)
            ans.push_back(it);

        return ans;
    }
};
