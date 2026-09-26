class Solution {
public:
    void search(vector<vector<char>>& grid , int i , int j){
        if( i<0|| i>=grid.size() ||j<0||j>=grid[i].size()) return ;
        if(grid[i][j]=='#' ||grid[i][j]=='0' ) return;
        grid[i][j]='#';
        search(grid , i-1 , j);
        search(grid , i+1 , j);
        search(grid , i , j-1);
        search(grid , i , j+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] =='1'){ 
                    count+=1;
                    search(grid , i , j);
                }
                    
            }
        }
    return count;

    }
};
