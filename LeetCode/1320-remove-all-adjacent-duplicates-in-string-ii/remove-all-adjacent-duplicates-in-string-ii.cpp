class Solution {
public:
    bool areLastK_1charSame(string& ans, char& newChar, int k_1) {
        int iterator = ans.size() - 1;
        for (int i = 0; i < k_1; i++) {
            if (newChar != ans[iterator])
                return false;
            iterator--;
        }
        return true;
    }

    string removeDuplicates(string s, int k) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            char& newChar = s[i];
            if (ans.size() < k - 1) {
                ans.push_back(newChar);
                } 
            else {
                if (areLastK_1charSame(ans, newChar, k - 1)) {
                    for(int j = 0; j < k - 1; j++)
                        ans.pop_back();
            }
            else 
                ans.push_back(newChar);
            }
        }
        return ans;
    }
};