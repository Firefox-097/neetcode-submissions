class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector <int> ans;
        unordered_map <int,int> sum;
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            if(sum.find(comp)!=sum.end()){
                ans.push_back(sum[comp]);
                ans.push_back(i);
                return ans;
            }
            else{
                sum[nums[i]] = i;
            }
        }
    return ans;
    }
};
