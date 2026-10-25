class Solution {
public:

    int m,n;
    // Depth first Search
    void dfs(vector<vector<int>>& grid,int r, int c){
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 1)
            return;    

            // mark the land cell as visited
            grid[r][c] = 1;
            // and now explore the connected cells
            dfs(grid,r+1,c); //Down
            dfs(grid,r-1,c); //up
            dfs(grid,r,c+1); // right
            dfs(grid,r,c-1); // left

    }

    

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove the connected islands
        // left and the right edges
        for(int r = 0;r < m;r++){
            if(grid[r][0] == 0)
                dfs(grid,r,0);

            if(grid[r][n-1] == 0)
                dfs(grid,r,n-1);
        }

        // for the top and the bottom
        for(int c = 0;c < n;c++){
            if(grid[0][c] == 0)
                dfs(grid,0,c);

            if(grid[m-1][c] == 0)
                dfs(grid,m-1,c);
        }
        // step 2: count the remaning after all the removals
        int count = 0;
        for(int r = 0;r < m;r++){
            for(int c = 0;c < n;c++){
                if(grid[r][c] == 0){
                    count++;
                    dfs(grid,r,c);
                }
            }
        }
        return count;
    }
};