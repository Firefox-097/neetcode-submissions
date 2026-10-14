class Solution {
public:
    void dfs(vector<vector<int>>& heights , int i , int j ,vector<vector<bool>>& ocean){
        if(i<0 || i>=heights.size() || j<0 || j >= heights[0].size()) return;
        if(ocean[i][j] == true ) return;
        ocean[i][j] = true ;
        if(j<heights[0].size()-1 && heights[i][j+1]>=heights[i][j]) dfs(heights , i,j+1 , ocean);
        if(i<heights.size()-1 && heights[i+1][j]>=heights[i][j]) dfs(heights , i+1,j , ocean);
        if(j > 0 && heights[i][j-1]>=heights[i][j]) dfs(heights , i,j-1 , ocean);
        if(i> 0 && heights[i-1][j]>=heights[i][j]) dfs(heights , i-1,j , ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pacific(row , vector<bool>(col, false));
        vector<vector<bool>> atlantic(row , vector<bool>(col, false));
        for(int j=0;j<col;j++) dfs( heights, 0 , j , pacific);
        for(int i=0;i<row;i++) dfs(heights , i , 0 , pacific);
        for(int j=0;j<col;j++) dfs( heights, row-1 , j , atlantic);
        for(int i=0;i<row;i++) dfs(heights , i , col-1 , atlantic);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j]== true && atlantic[i][j]==true) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
