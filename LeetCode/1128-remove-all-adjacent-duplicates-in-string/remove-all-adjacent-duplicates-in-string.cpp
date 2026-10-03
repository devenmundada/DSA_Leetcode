class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i = 0;i < s.size();i++){
            char  CurrCharacter = s[i];

            if(ans.empty()){
                // if ans is empty then sidha push kardo
                ans.push_back(CurrCharacter);
            }
            else if(CurrCharacter == ans.back()){
                ans.pop_back();
            }
            else if(CurrCharacter != ans.back()){
                ans.push_back(CurrCharacter);
            }
        }
        return ans;
    }
};