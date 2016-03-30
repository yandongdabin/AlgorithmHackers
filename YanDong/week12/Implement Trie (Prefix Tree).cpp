/**52ms
beat 95.44%

***/

#include<string>
#include<cstring>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        this->freq  = 0;
        memset(children,NULL,sizeof(children));
    }
public:
    char var;
    TrieNode *children[26];
    int freq;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(unsigned int i = 0;i<word.length();++i){
            int idx = word[i] - 'a';
            if(cur->children[idx] == NULL){
                cur->children[idx] = new TrieNode();
            }
            if(i == word.length()-1)
                cur->children[idx]->freq += 1;
            cur = cur->children[idx];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for(unsigned int i = 0;i<word.length();++i){
            int idx = word[i] - 'a';
            if(cur->children[idx] == NULL)
                return false;
            if(i == word.length()-1 && cur->children[idx]->freq > 0)
                return true;
            cur = cur->children[idx];
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(unsigned int i = 0;i<prefix.length();++i){
            int idx = prefix[i] - 'a';
            if(cur->children[idx] == NULL)
                return false;
            cur = cur->children[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
    return 0;
}
