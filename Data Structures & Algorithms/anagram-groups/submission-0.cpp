class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string , vector<string>> mpp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string dupl=strs[i];
            sort(dupl.begin(),dupl.end());
            mpp[dupl].push_back(strs[i]);
        }
        for(auto c:mpp){
            ans.push_back(c.second);
        }
    return ans;
    }
};
  