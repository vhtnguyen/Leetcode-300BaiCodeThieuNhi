//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include<string>
using namespace std;
class WordDictionary {
    public:
    WordDictionary* child[26];
    int countWord;
    WordDictionary() {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        countWord = 0;
    }

    void addWord(string word) {
        int ch;
        WordDictionary* temp = this;
        for (int i = 0; i < word.size(); ++i) {
            ch = word[i] - 'a';
            if (temp->child[ch] == nullptr) {
                temp->child[ch] = new WordDictionary;
            }
            temp = temp->child[ch];
        }
        temp->countWord++;
    }

    bool search(string word) {
        int ch;
        WordDictionary* temp = this;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0;j < 26;++j) {
                    if (temp->child[j] && temp->child[j]->search(word.substr(i + 1))) {
                        return true;
                    }
                }
                return false;
            }
            else {
                ch = word[i] - 'a';
            }
            if (temp->child[ch] == nullptr)
                return false;
            temp = temp->child[ch];
        }
        return temp && temp->countWord > 0;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

