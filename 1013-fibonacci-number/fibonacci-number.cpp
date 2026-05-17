
class Solution {
public:
// Deven Mundada
    int solveusingrecursion(int n){
        // base case
        if(n == 0 || n == 1){
            return n;
        }
        int ans  = solveusingrecursion(n-1) + solveusingrecursion(n-2);
        return ans;
    }

    // using DP solution
    // top-down approch
    // type of dp -> 1D dp -> dp array - 1D
       int solveusingmem(int n, vector<int> &dp ){
        // base case
        if(n == 0 || n == 1){
            return n;
        }
    // step 3 : base case ke baad, check if ans already exists or not 
        if(dp[n] != -1){
            return dp[n];
        }

        // step 2: Store and retuen the dp array
        dp[n] = solveusingmem(n-1,dp) + solveusingmem(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        // int ans = solveusingrecursion(n);
        // return ans;
    // step - 1 :
        vector<int> dp(n+1,-1);
         return solveusingmem(n,dp);
    } 
};