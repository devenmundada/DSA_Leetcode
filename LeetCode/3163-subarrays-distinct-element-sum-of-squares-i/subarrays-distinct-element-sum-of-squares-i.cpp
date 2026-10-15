class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        

        for(int i = 0;i < n;i++){
            bool seen[101] = {false};
            int count = 0;
            for(int j = i;j < n;j++){
                if(!seen[nums[j]]){
                    seen[nums[j]] = true;
                    count++;
                }
                ans += count * count;
            }

        }
        return ans;
    }
};