class Solution {
public:

    set<string> ans;

    void solve(string &str, int index,int balance,int CloseValaRemove,int OpenValaRemove,string &output){
        // base Case
        if(index == str.size()){
            if(balance == 0 && CloseValaRemove == 0 && OpenValaRemove == 0){
                ans.insert(output);
            }
            return;
        }
        // if the current charahter is '('
        if(str[index] == '('){
            // remove '('
            if(OpenValaRemove > 0){
                solve(str,index+1,balance,CloseValaRemove,OpenValaRemove-1,output);
            }
            // keep '('
            output.push_back('(');
            solve(str,index+1,balance+1,CloseValaRemove,OpenValaRemove,output);
            // backtrack
            output.pop_back();
        }
        // now the char is ')'
        else if(str[index] == ')'){
            // remove ')'
            if(CloseValaRemove > 0){
                solve(str,index+1,balance,CloseValaRemove - 1,OpenValaRemove,output);
            }
            // Keep ')' only if we have '(' open available
            if(balance > 0){
                output.push_back(')');
                solve(str,index + 1,balance - 1,CloseValaRemove,OpenValaRemove,output);
                // BackTrack
                output.pop_back();
            }
        }
        else{
            output.push_back(str[index]);
            solve(str,index + 1,balance,CloseValaRemove,OpenValaRemove,output);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        ans.clear();
        int balance = 0;
        int CloseValaRemove = 0;

        // minimum removals required 
        for(int i = 0;i < s.size();i++){
            char ch = s[i];

            if(ch == '('){
                balance++;
            }
            else if(ch == ')'){
                if(balance > 0){
                    balance--;
                }
                else{
                    CloseValaRemove++;
                }
            }
        }
        int OpenValaRemove = balance;

        string output = "";
        solve(s,0,0,CloseValaRemove,OpenValaRemove,output);

        return vector<string>(ans.begin(),ans.end());
    }
};