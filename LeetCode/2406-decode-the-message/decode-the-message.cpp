class Solution {
public:
    string decodeMessage(string key, string message) {
        // step 1: Create Mapping
        unordered_map<char,char> mapping;
        char space = ' ';
        mapping[space] = space;
        char start = 'a';
        int index = 0;

        while(start <= 'z' && index < key.length()){
            char CurrCharachter = key[index];
            // start -> mapping abcd... and all 
            // now mapping Curr charachter -> to the alphabet
            if(mapping.find(CurrCharachter) != mapping.end()){
                // if currcharchter ki mapping already present hai 
                // toh no need to store again
                index++;
            }
            else{
                // if already present nahi hai toh
                mapping[CurrCharachter] = start;
                start++;
                index++;
            }
        }
        // Step 2 : use mapping and decode the message
        string ans = "";
        for(int i = 0;i < message.length();i++){
            char msgCharachter = message[i];
            char mappedCharachter = mapping[msgCharachter];
            ans.push_back(mappedCharachter);
        }
        return ans;
    }
};