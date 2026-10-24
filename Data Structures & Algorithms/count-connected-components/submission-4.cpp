class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj, vector<bool>&vis){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i])
            dfs(i , adj , vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis (n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count ++;
                dfs(i, adj, vis);
            }
        }
    return count;
    }
};
