class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_map <char,int> mpp;
        int maxi=0,left=0,n=s.size();
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            maxi=max(maxi,mpp[s[right]]);
            while((right-left+1)-maxi>k){
                mpp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
    return ans;
    }
};
