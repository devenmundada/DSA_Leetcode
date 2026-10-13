class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        

        vector<int> squares;
        for(int i = 0; i < nums.size();i++){
            int val = nums[i];
            squares.push_back(val * val);
        }
        sort(squares.begin(),squares.end(),greater<int>());

        long long ans = 0;
        int n = squares.size();
        for(int  i = 0;i < n;i++){
            if(i < (n+1)/2){
                ans += squares[i];
            }
            else{
                ans -= squares[i];
            }
        }
        return ans;
    }
};