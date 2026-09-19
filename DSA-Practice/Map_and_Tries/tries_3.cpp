#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode{
    public:
    char value;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data){
        value = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root,string word){
    // base case - ek time aisa aayega ki string empty hogyi hai
    if(word.length() == 0){
        root -> isTerminal = true;
        return;
    }

    // 1 case solve kar dete hai
    // 1 charachter ko tie mai insert kar deta hu
    char ch = word[0];
    TrieNode* child;

    // present hai toh vha chale jao
    // absent hai toh create kardo
    if(root->children.count(ch) == 1){ //jo charachet dhund rhe hai vo mil gaya
        child = root -> children[ch];   // toh usse ek shift kar do
    }
    else{
        // absent
        child = new TrieNode(ch);
        // fir usse link kar do
        root->children[ch] = child;
    }
    // baaki recursion sambhal lega
    insertIntoTrie(child,word.substr(1));
}

bool searchTrie(TrieNode* root,string word){
    // base case
    // check last character terminal h ya nahi
    if(word.length() == 0){
        // iska matlab root mai last chrachter pada hua hai
        return root->isTerminal;
    }
    // 1 case solve kar na hai
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root -> children.end()){
        // present 
        child = root->children[ch];
    }
    else{
        // absent
        return false;
    }
    // ...baki recursion ssambhal lega
    bool recursionkaAns = searchTrie(child,word.substr(1));
    return recursionkaAns;
}

void deleteWord(TrieNode* root,string word){
    // base case - ek time aisa hoga jab word empty rhage
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    // 1 case mai smabhal lunga
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return;
    }

    // baaki recursion sambhal lega
    deleteWord(child,word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root, "cover"); 
    insertIntoTrie(root, "car"); 
    insertIntoTrie(root, "coat"); 
    insertIntoTrie(root, "snake"); 
    insertIntoTrie(root, "coward"); 
    insertIntoTrie(root, "tag"); 

    bool ans = searchTrie(root, "cover");

    if(ans){
        cout << "Found" << endl;
    }
    else{
        cout <<"Not found" << endl;
    }

    deleteWord(root,"cover");

    ans = searchTrie(root, "cover");
    if(ans){
        cout << "Found" << endl;
    }
    else{
        cout <<"Not found" << endl;
    }
}