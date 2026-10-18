class Solution {
public:

    int digitSum(int x){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {

        // store digit sum, value, and the original index
        vector<array<int,3>>arr;
        for(int i = 0;i < nums.size();i++){
            arr.push_back({digitSum(nums[i]),nums[i],i});
        }
        // sort by the digit sum
        sort(arr.begin(),arr.end());

        // part 4: Count the swaps using cycles
        vector<bool> visited(nums.size(),false);
        int swap = 0;

        for(int i = 0;i < nums.size();i++){
            if(visited[i] || arr[i][2] == i)
            continue;

        int CycleSize = 0;
        int j = i;

        while(!visited[j]){
            visited[j] = true;
            j = arr[j][2];
            CycleSize++;
        }
        if(CycleSize > 0){
        swap += CycleSize - 1;
        }
        }
        return swap;
    }
};