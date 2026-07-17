class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> lft(n),rght(n),ans(n);
        lft[0]=1;
        rght[n-1]=1;
        for(int i=1;i<n;i++){
            lft[i]=lft[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rght[i]=rght[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=lft[i]*rght[i];
        }
    return ans;
    }
};
