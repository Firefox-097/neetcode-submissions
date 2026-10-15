class Solution {
public:
    bool dfs(int node ,vector<vector<int>> &adj,vector <int> &states ){
        if (states[node]==1) return false;
        if (states[node]==2) return true; 
        states[node]=1;
        for(auto i: adj[node]){
            if(!dfs(i , adj , states)){
                    return false;
                }
        }
        states[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector <int> states(numCourses , 0);
        for(int i=0;i<numCourses;i++){
            if(states[i]==0){
                if(!dfs(i , adj , states)){
                    return false;
                }
            }
        }
        return true;
    }
};
