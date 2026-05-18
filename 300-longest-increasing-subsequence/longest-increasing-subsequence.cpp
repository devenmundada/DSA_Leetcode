class Solution {
public:

    int solveusingRec(vector<int>& arr,int curr,int prev){
        // base case
        if(curr >= arr.size()){
            return 0;
        }
        // include
        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            inc = 1 + solveusingRec(arr,curr+1,curr);
        }
        int exc = 0 + solveusingRec(arr,curr+1,prev);
        int finalans = max(inc,exc);
    return finalans;
    }

// 2D - DP method because it is geeting TLE

     int solveusingMem(vector<int>& arr,int curr,int prev,vector<vector<int>> &dp){
        // base case
        if(curr >= arr.size()){
            return 0;
        }
        // Step 3:
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        // include
        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            inc = 1 + solveusingMem(arr,curr+1,curr,dp);
        }
        int exc = 0 + solveusingMem(arr,curr+1,prev,dp);
        dp[curr][prev+1] = max(inc,exc);
        return dp[curr][prev+1];
    }


    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // return solveusingRec(nums,curr,prev);
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveusingMem(nums,curr,prev,dp);
    }
};