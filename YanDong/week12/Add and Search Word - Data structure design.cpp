class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        this->freq  = 0;
        for(int i = 0;i<26;++i){
            children[i] = NULL;
        }
    }
public:
    char var;
    TrieNode *children[26];
    int freq;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

   // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      return search_helper(word.c_str(),root);
    }
private:
    bool search_helper(const char *str,TrieNode *root){
        TrieNode *cur = root;
        for(int i =0;str[i];++i){
            if(!cur) return false;
            if(str[i] != '.'){
                cur = cur->children[str[i] - 'a'];
            }else if(str[i] == '.'){
                for(int j = 0;j<26;++j){
                    if(search_helper(str+i+1,cur->children[j]))
                        return true;
                }
                return false;
            }

        }
        return cur && cur->freq > 0;
    }


private:
    TrieNode* root;
};
