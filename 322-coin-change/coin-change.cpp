class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        // Base Case
        if (amount == 0) {
            return 0;
        }
        // if amount < 0
        int minCoinAns = INT_MAX;
        // har amaount ke liye pure array koo traverse karna padega
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            // if coin value > amount then no need for recc
            // if coin value <= amount then call recursive function
            if (coin <= amount) {
                // 1 coin toh use ho gya hai, amount becomes amount-coins
                // baaki recursion sambhal lega
                int recursionAns = solve(coins, amount - coin);
                // ho skata hai ki recc ka answer invalid aaye
                // invalid -> recc ka ans = INT_MAX
                // if valid -> recc ka ans -> not equal to INT_MAX
                if (recursionAns != INT_MAX) {
                    // valid answer aaya hai
                    int coinUsed = 1 + recursionAns;
                    minCoinAns = min(minCoinAns, coinUsed);
                }
            }
        }
        return minCoinAns;
    }
    // 1-D DP
    int solveMemo(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        // step 3: check if already exists
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int minCoinAns = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            if (coin <= amount) {
                int recursionAns = solveMemo(coins, amount - coin, dp);
                if (recursionAns != INT_MAX) {
                    int coinUsed = 1 + recursionAns;
                    minCoinAns = min(minCoinAns, coinUsed);
                }
            }
        }
        // step 2: DP answer store and return
        dp[amount] = minCoinAns;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount){
        //     int ans = solve(coins,amount);
        //     if(ans == INT_MAX){
        //         return -1;
        //     }
        //     return ans;
        // }
        // Step 1: Create Dp
        vector<int> dp(amount + 1, -1);
        int ans = solveMemo(coins, amount, dp);
        if (ans == INT_MAX) {
        return -1;
    }
    return ans;
}
}
;