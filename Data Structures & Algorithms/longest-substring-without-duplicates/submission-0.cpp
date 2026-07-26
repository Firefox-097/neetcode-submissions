class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        unordered_set<char> maxi;
        int n=s.size();
        int left=0,right=0;
        while(right<n){
            if(maxi.find(s[right])==maxi.end()){
                maxi.insert(s[right]);
                len=max(len,right-left+1);
                right++;
            }
            else {
                maxi.erase(s[left]);
                left++;
            }
        }
    return len;
    }
};
