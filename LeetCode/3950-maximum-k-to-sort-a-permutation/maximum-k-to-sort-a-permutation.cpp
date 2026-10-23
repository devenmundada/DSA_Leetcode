class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        bool sorted  = true;

        for(int i = 0;i < nums.size();i++){
            // Base Condition
            if(nums[i] != i){
                sorted  = false;
                k &= nums[i];
            }
            
    
        }
        if(sorted){
         return 0;
        }
        return k;
    }
};