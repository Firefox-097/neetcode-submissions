class Solution {
public:
    bool dfs(int parent,int node, vector<vector<int>> &adj,vector<bool>&visited){
        visited[node]=true;
        for(auto i:adj[node]){
            if(i==parent) continue;
            if(visited[i]) return false;
            if(!dfs(node,i,adj,visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>visited(n , 0);
        if(!dfs(-1,0,adj,visited)) return false;
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
