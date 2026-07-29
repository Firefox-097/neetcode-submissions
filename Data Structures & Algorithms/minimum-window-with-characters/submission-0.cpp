class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> reqd;
        for(auto it:t) reqd[it]++;
        int left=0,start=0,minLen=INT_MAX;
        unordered_map<char,int> got;
        int need=reqd.size();
        int formed=0;
        for(int right=0;right < s.size();right++){
            got[s[right]]++;
            if(reqd.count(s[right])&& got[s[right]]==reqd[s[right]] ) formed ++;
            while(formed==need){
                if(right-left+1 < minLen){
                    minLen=right-left+1;
                    start=left;
                }
                got[s[left]]--;
            if(reqd.count(s[left])&& got[s[left]]<reqd[s[left]] ) formed --;
            left++;
            }
        
        }
    if(minLen==INT_MAX) return "";
    return s.substr(start,minLen);
    }
};
