class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        priority_queue<pair<int , int>> val2;
        unordered_map<int , int> val1;
        for(int x:nums) val1[x]++;
        for(auto &i:val1) val2.push({i.second,i
         .first});
        for(int i=0;i<k;i++){
            ans.push_back(val2.top().second);
            val2.pop();
        }
        return ans;
    }
};
