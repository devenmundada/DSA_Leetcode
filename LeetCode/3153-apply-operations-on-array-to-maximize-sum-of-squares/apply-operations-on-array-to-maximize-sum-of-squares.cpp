class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long MOD = 1e9 + 7;

        // step 1: store the each bit count
        vector<int> count(31,0);

        for(int i = 0;i < nums.size();i++){
            for(int bit = 0; bit < 31;bit++){
                if(nums[i] & (1 << bit)){
                    count[bit]++;
                }
            }
        }
        // step 2: construct the K numbers
        long ans = 0;
        for(int i = 0;i < k;i++){
            long num = 0;
            for(int bit = 0; bit < 31;bit++){
            if(count[bit] > 0){
                num = num | (1LL << bit);
                count[bit]--;
            }
        }
            ans = (ans+num * num) % MOD;
    }
        return ans;
    }
};