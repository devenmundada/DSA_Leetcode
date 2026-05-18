class Solution {
public:

    int solve(vector<int>& arr,int lastindex,int i){
        // base case
        if(i >= arr.size()){
            return 0;
        }
        // 1 case hum solve karege baki recc
        // increment tab he kar sakte hai jab last element curr element se bada ho
        int curr = arr[i];
        int inc = 0;
        // include
        if(lastindex == -1 || curr > arr[lastindex]){
            inc = 1 + solve(arr,i,i+1);
        }
        // Exclude
        int exc = 0 + solve(arr,lastindex,i+1);
        
        int finalAns = max(inc,exc);
        return finalAns;
    }


// 2D - DP method because it is geeting TLE
    int solveMemo(vector<int>& arr,int lastindex,int i,vector<vector<int>>& dp){
        // base case
        if(i >= arr.size()){
            return 0;
        }
        // step - 3 check if answer already exists?
        if(dp[lastindex+1][i] != -1){
            return dp[lastindex+1][i];
        }

        // 1 case hum solve karege baki recc
        // increment tab he kar sakte hai jab last element curr element se bada ho
        int curr = arr[i];
        int inc = 0;
        // include
        if(lastindex == -1 || curr > arr[lastindex]){
            inc = 1 + solveMemo(arr,i,i+1,dp);
        }
        // Exclude
        int exc = 0 + solveMemo(arr,lastindex,i+1,dp);
        // step 2: store and return in dp
        dp[lastindex+1][i] = max(inc,exc);
        return dp[lastindex+1][i];
    }


    int lengthOfLIS(vector<int>& nums) {
        int lastindex = -1;
        int i = 0;
        // return solve(nums,lastindex,i);

        // step 1: create and pass DP array
        int n = nums.size();
        vector<vector<int> > dp(n+2,vector<int>(n+1,-1));

        return solveMemo(nums,lastindex,i,dp);
    }
};