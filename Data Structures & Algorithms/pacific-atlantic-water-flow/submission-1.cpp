class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& visited) {

        if(i < 0 || i >= heights.size() ||
           j < 0 || j >= heights[0].size())
            return;

        if(visited[i][j])
            return;

        visited[i][j] = true;

        // Move to a cell that is same height or higher
        if(i > 0 && heights[i - 1][j] >= heights[i][j])
            dfs(heights, i - 1, j, visited);

        if(i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j])
            dfs(heights, i + 1, j, visited);

        if(j > 0 && heights[i][j - 1] >= heights[i][j])
            dfs(heights, i, j - 1, visited);

        if(j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j])
            dfs(heights, i, j + 1, visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific: top row + left column
        for(int i = 0; i < rows; i++)
            dfs(heights, i, 0, pacific);

        for(int j = 0; j < cols; j++)
            dfs(heights, 0, j, pacific);

        // Atlantic: bottom row + right column
        for(int i = 0; i < rows; i++)
            dfs(heights, i, cols - 1, atlantic);

        for(int j = 0; j < cols; j++)
            dfs(heights, rows - 1, j, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};