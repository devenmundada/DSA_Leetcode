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

    // Using bottom-up approch
    int solveusingTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+2,0);

        for(int i = n-1;i >= 0;i--){
        int include = nums[i] + dp[i+2];
        int exclude = 0 + dp[i+1];
        dp[i] = max(include,exclude);
        }
        return dp[0];
    }


    int solveUsingspaceopti(vector<int>&nums){
        int n = nums.size();

        int next1 = 0;
        int next2 = 0;

        for(int i = n-1;i>=0;i--){
        int include = nums[i] + next2;
        int exclude = 0 + next1;
        int curr = max(include,exclude);
        // Shifting -> ye yaad rakh na hai...bhul jaate hai
        next2 = next1;
        next1 = curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
    //  return solve(nums,0);   
    int n = nums.size();
    vector<int> dp(n+1,-1);
    int i = 0;
    // return solvememo(nums,i,dp);
    // return solveusingTab(nums);
    return solveUsingspaceopti(nums);
    }
};