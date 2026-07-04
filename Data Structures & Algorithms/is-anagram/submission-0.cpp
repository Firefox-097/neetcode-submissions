class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unordered_map <char , int> cmp;
        for (char i:s){
            cmp[i]++;
        }
        for(char c:t){
            if(cmp.find(c)==cmp.end())return false;
            cmp[c]--;
            if(cmp[c]<0) return false;
        }
    return true;
    }
};
