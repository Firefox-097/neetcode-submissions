class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto i:strs){
            ans+=to_string(i.size())+"#"+i;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector <string> dec;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int count=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,count);
            dec.push_back(word);
            i=j+count+1;
        }
        return dec;
    }
};
