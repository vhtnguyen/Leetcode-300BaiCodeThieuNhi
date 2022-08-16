#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
    Trie* child[26];
    int countWord;
    Trie() {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        countWord = 0;
    }
    void insert(string s) {
        int ch;
        Trie* temp = this;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == nullptr)
                temp->child[ch] = new Trie;
            temp = temp->child[ch];
        }
        temp->countWord++;
    }

    bool search(string s) {
        int ch;
        Trie* temp = this;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == nullptr)
                return false;
            temp = temp->child[ch];
        }
        return temp->countWord > 0;
    }

    bool startsWith(string s) {
        int ch;
        Trie* temp = this;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == nullptr)
                return false;
            temp = temp->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



