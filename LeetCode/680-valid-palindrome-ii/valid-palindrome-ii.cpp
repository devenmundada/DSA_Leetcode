class Solution {
public:

bool checkPalindrome(string str, int start, int end){
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        // valid palindrome
        return true;
}

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            // different
            else{
                // s[i] != s[j]
                // 2 options
                // remove i and check
                // 2nd remove j and check
                bool ans1 = checkPalindrome(s,i+1,j);
                bool ans2 = checkPalindrome(s,i,j-1);

                bool finalAns = ans1 || ans2;
                return finalAns;
            }
        }
        return true;
    }
};