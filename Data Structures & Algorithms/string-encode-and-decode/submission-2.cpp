class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(string s : strs){
            str+=to_string(s.size())+"#"+s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector <string> ans;
        for(int i=0;i<s.length();){
            int j=i;
            while(s[j]!='#') j++;
            int count=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,count);
            ans.push_back(word);
            i=j+count+1;
        }
        return ans;
    }
};