
#include <bits/stdc++.h>
using namespace std;

//Solution using Trie manual implement

/*
class Solution {
    public:
    int MX; // maximum length available
    Solution() { MX = 0; }
    struct Node {
        Node* child[26];
        int length;
    };
    Node* newNode() {
        Node* node = new Node;
        if (node == nullptr)
            return nullptr;
        node->length = 0;
        for (int i = 0; i < 26; ++i) {
            node->child[i] = nullptr;
        }
        return node;
    };
    bool addWord(Node* root, string s, bool firstWord) {
        int ch;
        Node* temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == nullptr) {
                if (firstWord) { // If s is the first word of prefix tree
                    temp->child[ch] = newNode();
                    temp->child[ch]->length = temp->length + 1;
                }
                else if (i == 0) //If prefix tree have more than one brach it means there is no common prefix valid
                    return false;
                else {// a valid shorter prefix exist
                    MX = i;
                    return true;
                }
            }
            if (!firstWord && temp->length >= MX)
                return true;
            temp = temp->child[ch];
        }
        if (firstWord || temp->length < MX)
            MX = temp->length;
        return true;
    }
    string longestCommonPrefix(vector<string>& s) {
        Node* root = newNode();
        addWord(root, s[0], true);
        int n = s.size();
        for (int i = 1;i < n;++i) {
            if (!addWord(root, s[i], false))
                return "";
        }
        return s[0].substr(0, MX);
    }
};

int main() {

    Solution x;
    vector<string>s;
    s.push_back("flower");
    s.push_back("flowe");
    s.push_back("flowr");
    x.longestCommonPrefix(s);
    return 0;
}
*/



//because the range of s.size() and s[i].length() within [0;200] -> can using sorting alg
//...
