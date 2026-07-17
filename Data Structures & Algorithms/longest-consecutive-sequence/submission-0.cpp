class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> ans;
        int maxLen=0;
        for(auto it:nums) ans.insert(it);
        for(auto it : ans){
            if(ans.find(it-1)==ans.end()){
                int count =1;
                int x=it;
                while(ans.find(x+1)!= ans.end()){
                    count +=1;
                    x+=1;
                }
            maxLen=max(maxLen,count);
            }
        }
    return maxLen;
    }
};
