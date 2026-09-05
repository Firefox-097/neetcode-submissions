class Solution {
public:
    void solve(int i,int target,vector<int> &nums,vector<vector<int>>& ans, vector<int> &val){
        if(target ==0){
            ans.push_back(val);
            return;
        }
        if(target <0 || i ==nums.size()) return;
        val.push_back(nums[i]);
        solve(i,target-nums[i],nums,ans,val);
        val.pop_back();
        solve(i+1,target,nums,ans,val);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>val;
        solve(0,target,nums , ans , val);
        return ans;
    }
};
