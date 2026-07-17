class Solution {
public:
    bool isPalindrome(string s) {
        string word = alphanum(s);
        int n=word.length();
        for(int i=0,j=n-1;i<j;i++,j--){
            if(word[i]!=word[j]) return false;
        }
    return true;
    }
    string alphanum(string s){
        string word;
        for(auto i: s){
            if(isalnum(i)) word+=tolower(i);
        }
    return word;
    }
};
