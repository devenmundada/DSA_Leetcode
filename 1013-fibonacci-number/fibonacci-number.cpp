
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
// Approch :  BOTTOM-UP APPROCH
    int solveusingtabulation(int n){
        // step 1: create dp array
        vector<int> dp(n+1,-1); 
        // step 2: analyze base cases and update dp array
        dp[0] = 0;
        if(n == 0){
            return 0;
        }
        dp[1] = 1;
        // step 3: check the parameter 
        // recursion : n -> 0
        // reverse : 0 -> n
        for(int i = 2; i <= n;i++){ //i=2 because hume already i=0(0) and i=1(1) ans pata hai
            // copy-paste
            dp[i] = dp[i-1] + dp[i-2];
        }
        // answer return 
        return dp[n];
    }

// space opitmazation approch
     int solveusingtabulationOptimized(int n){
        // step 1: create dp array
        // vector<int> dp(n+1,-1); //no need to create array
        // step 2: analyze base cases and update dp array
        // dp[0] = 0;
        if(n == 0 || n == 1){
            return n;
        }
        int prev = 0;
        int curr = 1;
        // dp[1] = 1;
        // step 3: check the parameter 
        // recursion : n -> 0
        // reverse : 0 -> n
        for(int i = 2; i <= n;i++){ //i=2 because hume already i=0(0) and i=1(1) ans pata hai
           int ans = curr + prev;
           prev = curr; //previoues ko aage bada diya
           curr = ans;
    }
    return curr;
}

    int fib(int n) {
        // int ans = solveusingrecursion(n);
        // return ans;
    // step - 1 :
        // vector<int> dp(n+1,-1);
         return solveusingtabulationOptimized(n);
    } 
};