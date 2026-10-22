class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }
};