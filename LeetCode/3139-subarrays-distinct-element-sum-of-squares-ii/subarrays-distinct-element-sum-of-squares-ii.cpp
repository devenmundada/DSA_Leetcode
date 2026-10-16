class Solution {
    static const int MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    // incrment for the entire segment
    
    void apply(int node,int left, int right, long long val){
        long long len = right - left + 1;
        long long oldSum = tree[node].sum;

        tree[node].sq = (tree[node].sq + 2LL * val * oldSum 
                        + val * val % MOD * len) % MOD;
        
        tree[node].sum = (oldSum + val * len) % MOD;

        tree[node].lazy += val;
    }

// Pass a pending update to the children.
    void push(int node, int left, int right) {
        if (tree[node].lazy == 0 || left == right)
            return;

        int mid = left + (right - left) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, left, mid, val);
        apply(node * 2 + 1, mid + 1, right, val);

        tree[node].lazy = 0;
    }

    // Increment every position in [ql, qr].
    void update(int node, int left, int right,
                int ql, int qr, long long val) {
        if (qr < left || right < ql)
            return;

        if (ql <= left && right <= qr) {
            apply(node, left, right, val);
            return;
        }

        push(node, left, right);

        int mid = left + (right - left) / 2;

        update(node * 2, left, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, right,
               ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq +
             tree[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n + 5, Node{});

        // Last occurrence of each value.
        vector<int> lastSeen(100001, -1);

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            // Only these starting positions gain
            // one new distinct element.
            int left = lastSeen[x] + 1;

            update(1, 0, n - 1, left, r, 1);

            lastSeen[x] = r;

            // Root stores the sum of squares for
            // all subarrays ending at index r.
            ans = (ans + tree[1].sq) % MOD;
        }

        return (int)ans;
    }
};