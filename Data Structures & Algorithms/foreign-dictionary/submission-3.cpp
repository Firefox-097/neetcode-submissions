class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    string ans;

    bool dfs(int node) {
        vis[node] = 1;

        for (auto i : adj[node]) {
            if (vis[i] == 1) return false;

            if (vis[i] == 0) {
                if (!dfs(i)) return false;
            }
        }

        vis[node] = 2;
        ans += char(node + 'a');
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        adj.clear();
        adj.resize(26);
        vis.assign(26, 0);
        ans = "";

        vector<bool> present(26, false);

        for (auto word : words) {
            for (auto ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < (int)words.size() - 1; i++) {
            string a = words[i];
            string b = words[i + 1];

            int j = 0;
            int len = min(a.size(), b.size());

            while (j < len && a[j] == b[j]) {
                j++;
            }

            if (j == len) {
                if (a.size() > b.size()) return "";
            } else {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
            }
        }

        for (int i = 0; i < 26; i++) {
            if (present[i] && vis[i] == 0) {
                if (!dfs(i)) return "";
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};