class Solution {
public:
    int expandAroundCenter(string str, int i, int j) {
        int count = 0;
        while (i >= 0 && j <= str.size() && str[i] == str[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int TotalCount = 0;
        for (int center = 0; center < s.size(); center++) {

            // ODD
            int i = center;
            int j = center;
            int odd = expandAroundCenter(s, i, j);

            // EVEN
            i = center;
            j = center + 1;
            int even = expandAroundCenter(s, i, j);

            TotalCount = TotalCount + odd + even;
        }
        return TotalCount;
    }
};