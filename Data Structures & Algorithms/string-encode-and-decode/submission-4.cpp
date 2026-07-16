class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for( auto it: strs){
            ans+=to_string(it.size())+"#"+it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans1;
        for(int i=0; i<s.size();){
            int count;
            int j=i;
            while(s[j]!='#')
                j++;
            count=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,count);
            ans1.push_back(word);
            i=j+count+1;
        }
        return ans1;
    }
};
