class Solution {
public:

    void Normalize(string &str){
        char start = 'a';
        unordered_map<char,char> mapping;

        for(int i = 0;i < str.length();i++){
            char StringCharachter = str[i];
            if(mapping.find(StringCharachter) == mapping.end()){
                // if mapping phele se present nhi hai toh 
                mapping[StringCharachter] = start;
                start++;
            }
        }
        // now mapping create ho chuki hai 
        // string str ko update update normalise kardo using mapping
        for(int i = 0;i < str.length();i++){
            char mappedCharachter = mapping[str[i]];
            str[i] = mappedCharachter;
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // pattern ko normalise karo
        Normalize(pattern);
        // lets now traverse on words -> normalize them -> and check ki vo pattern same hai ki nhi
        for(int i = 0;i < words.size();i++){
            // ith word
            string currWord = words[i];
            // normalise karo word ko
            string currWordCopy = currWord;
            Normalize(currWord);
            if(currWord.compare(pattern) == 0){
                // if both the normaised string are compared and equal
                ans.push_back(currWordCopy);
            }
        }
        return ans;
    }
};