
class Solution {
public:
// Deven Mundada
    int solveusingrecursion(int n){
        // base case
        if(n == 0 || n == 1){
            return n;
        }
        int ans  = solveusingrecursion(n-1) + solveusingrecursion(n-2);
        return ans;
    }

    int fib(int n) {
        int ans = solveusingrecursion(n);
        return ans;
    }
};