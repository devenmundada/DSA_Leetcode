class Solution {
public:

    int m,n;
    long long dfs(vector<vector<int>>& grid, int row,int col){
        // stop if outside the grid
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0){
            return 0;
        }
        long long sum = grid[row][col];

        // mark the cell as visited
        grid [row][col] = 0;

        sum += dfs(grid,row - 1,col); //up
        sum += dfs(grid,row + 1,col); //down
        sum += dfs(grid,row,col-1); //left 
        sum += dfs(grid,row,col+1); //right

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
         n = grid.size();
         m = grid[0].size();
        int count = 0;

        for(int row = 0;row < n;row++){
            for(int col = 0;col < m;col++){
                // founded a unvisited cell
                if(grid[row][col] > 0){
                    long long sum = dfs(grid,row,col);

                    // if the sum % k == 0 then increse the count
                if(sum % k == 0){
                    count++;
                }
                }
            }
        }
        return count;
    }
};