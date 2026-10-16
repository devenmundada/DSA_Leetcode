class Solution {
public:

    //      bool areLastK_1charSame(string& ans, char& newChar, int k_1) {
    //     int iterator = ans.size() - 1;
    //     for (int i = 0; i < k_1; i++) {
    //         if (newChar != ans[iterator])
    //             return false;
    //         iterator--;
    //     }
    //     return true;
    // }

    string removeDuplicates(string s, int k) {
        // Two pointer approch
        int i = 0, j = 0;
        vector<int> count(s.size());
        while(j < s.size()){
            s[i] = s[j];
            count[i] = 1;
            if(i > 0 && s[i] == s[i-1])
                count[i] += count[i-1];
            if(count[i] == k)
                    i -= k;
                    i++,j++;
        }
        return s.substr(0,i);
    }
};