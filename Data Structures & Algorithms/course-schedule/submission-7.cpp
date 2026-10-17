class Solution {
public:
    bool dfs(vector<int>&state , vector<vector<int>>& adj , int i){
        if(state[i]==1) return false;
        if(state[i]==2) return true; 
        state[i]=1;
        for(auto neighbour:adj[i]){
            if(!dfs(state  , adj , neighbour)){
                return false;
            }
        }
        state[i]=2;
    return true;
    } 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> state(numCourses);
        for(int i=0;i<numCourses;i++){
            state[i]=0;
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(state  , adj , i)){
                return false;
            }
        }
    return true;
    }
};
