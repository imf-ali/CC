class Solution {
public:
    void find(vector<int> &nums,int l,int r,vector<vector<int>> &ans){

        if(l == r){
            ans.push_back(nums);
            return;
        }

        for(int i=l;i<=r;i++){
            swap(nums[i],nums[l]);
            find(nums,l+1,r,ans);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        find(nums,0,n-1,ans);

        return ans;
    }
};
