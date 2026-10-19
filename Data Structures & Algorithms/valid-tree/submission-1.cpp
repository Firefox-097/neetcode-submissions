class Solution {
public:
    bool dfs(int node ,int parent, vector<vector<int>>& adj , vector<bool>&vis){
        vis[node]=1;
        for(auto i: adj[node]){
            if(i == parent ) continue;
            if(vis[i]==1 ) return false;
            if(!dfs(i , node , adj , vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n) ;
        for(auto i: edges){
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>vis(n, 0);
        if(!dfs(0 , -1 , adj , vis)) return false;
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;

    }
};
