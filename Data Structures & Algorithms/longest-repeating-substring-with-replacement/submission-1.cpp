class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,n=s.size(),left=0;
        unordered_map<char,int> freq;
        int maxi=0;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            maxi=max(maxi,freq[s[right]]);
            while((right-left+1)-maxi>k){
                freq[s[left]]--;
                left++;
            }
        ans=max(ans,right-left+1);
        }
    return ans;
    }
};
