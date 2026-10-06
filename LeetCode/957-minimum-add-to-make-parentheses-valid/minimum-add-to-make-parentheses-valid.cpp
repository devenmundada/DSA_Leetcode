class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int balance = 0;

        for(int i = 0;i <= s.length();i++){
            if(s[i] == '('){
                balance++;
            }
            else if(s[i] == ')'){
                if(balance > 0){
                balance--;
                }
                else{
                ans++;
                }

            }
        }
        return ans + balance;
    }
};