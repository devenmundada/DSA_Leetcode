class Solution {
public:

    int solve(vector<int>& nums,int i){
        // base case
        if(i >= nums.size()){
            return 0;
        }
    // 1 case hume solve karna hai
    // incl-excl
    int include = nums[i] + solve(nums,i+2);
    int exclude = 0 + solve(nums,i+1);
    int finalAns = max(include,exclude);
    return finalAns;
    }

    // 1-D DP
    // top-down approch -> recursion + memoisation
     int solvememo(vector<int>& nums,int i,vector<int>& dp){
        // base case
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

    // 1 case hume solve karna hai
    // incl-excl
    int include = nums[i] + solvememo(nums,i+2,dp);
    int exclude = 0 + solvememo(nums,i+1,dp);
    dp[i] = max(include,exclude);
    return dp[i];
    }

    int rob(vector<int>& nums) {
    //  return solve(nums,0);   
    int n = nums.size();
    vector<int> dp(n+1,-1);
    int i = 0;
    return solvememo(nums,i,dp);
    }
};