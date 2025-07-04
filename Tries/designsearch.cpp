#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    bool isTerminal;
    unordered_map<char, Node*> children;
    Node(char data){
        this->data = data;
        this->isTerminal = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = curr->children[ch];
            }
        }
        curr->isTerminal = true;
    }

    bool DFS(string& word, int ind, Node* curr) {
        if (ind == word.size()) return curr->isTerminal;

        char ch = word[ind];
        if (ch == '.') {
            for (auto& [childChar, childNode] : curr->children) {
                if (DFS(word, ind + 1, childNode)) return true;
            }
            return false;
        } else {
            if (!curr->children.count(ch)) return false;
            return DFS(word, ind + 1, curr->children[ch]);
        }
    }
    
    bool search(string word) {
        return DFS(word, 0, root);
    }
};

int main() {

    return 0;
}