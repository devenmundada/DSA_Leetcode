class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        // priority_queue<int> pq;

        vector<long long> freq(100001,0);
        long long sum = 0;

        for(int i = 0;i < nums1.size();i++){
            // pq.push(abs(nums1[i] - nums2[i]));
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            sum += d;
        }
        long long k = (long long)k1 + k2;
        if(k >= sum){
            return 0;
        }

        for(int d = 100000;d > 0 && k > 0;d--){
            long long move = min(k,freq[d]);

            freq[d] -= move;
            freq[d-1] += move;
            k -= move;
        }
        // while(k > 0 && pq.top() > 0){
        //     int largestdiff = pq.top();
        //     pq.pop();

        //     largestdiff--;

        //     pq.push(largestdiff);
        //     k--;
        // }
        long long ans = 0;
        // while(!pq.empty()){
        //     long long d = pq.top();
        //     pq.pop();
        for(int d = 1;d <= 100000;d++){
            ans += freq[d] * d * d;
        }
        return ans;
    }
};