class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][x]  can reach cell(i,j)
        vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(n,vector<bool>(1024,false)));

        // starting cell
        dp[0][0][grid[0][0]] = true;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                for(int x = 0;x < 1024;x++){

                    if(!dp[i][j][x]){
                        continue;
                    }
                    // move right
                    if(j+1 < n){
                        int newXor = x ^ grid[i][j+1];
                        dp[i][j+1][newXor] = true;  
                    }
                    // move down
                    if(i+1 < m){
                        int newXor = x ^ grid[i+1][j];
                        dp[i+1][j][newXor] = true;
                    }
                }
            }
        }
        // now find the minimum path after the xor to the destination
        for(int x=0;x < 1024;x++){
            if(dp[m-1][n-1][x]){
            return x;
            }
        }
        return -1;
    }
};