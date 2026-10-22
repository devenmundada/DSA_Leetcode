class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos0 = 0;
        int posLast = 0;

        // finding the position of 0 and n-1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                pos0 = i;
            if (nums[i] == n - 1)
                posLast = i;
        }

        bool increasing = true;

        for (int k = 0; k < n; k++) {
            if (nums[(pos0 + k) % n] != k) {
                increasing = false;
                break;
            }
        }

        if (increasing)
            return min(pos0,n-pos0+2);

        bool decreasing = true;

        for (int k = 0; k < n; k++) {
            if (nums[(pos0 + k) % n] != (n - k) % n) {
                decreasing = false;
                break;
            }
        }

        if (decreasing) {
            return min(posLast + 1, n - pos0);
        }
        return -1;
    }
};