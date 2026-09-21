class Solution {
public:

    int sortingMethod(vector<int> &nums){
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == i) 
            continue;
            else
            return i;
        }  
        return nums.size(); 
    }

    int xorr(vector<int> &nums){
       int ans = 0;
    //  1.XOR for all values of arrya
        for(int i = 0;i < nums.size();i++){
            ans ^= nums[i];
        }
        // 2. XOR the range intems
        int N = nums.size();
        for(int i = 0;i <= N;i++){
            ans ^= i;
        }
        return ans;
    }

    int missingNumber(vector<int>& nums) {
        // return sortingMethod(nums);
        return xorr(nums);
    }
};