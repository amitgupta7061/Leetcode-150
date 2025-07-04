#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    string endingword;
    unordered_map<char, Node*> children;

    Node(char data){
        this->data = data;
        this->endingword = "";
    }
};

class Solution {
public:
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void pushinTries(string word, Node* root){
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
        curr->endingword = word;
    }
    void DFS(vector<vector<char>> &board, int r, int c, Node* root, vector<string> &result){
        char ch = board[r][c];
        if(!root->children.count(ch)) return;

        root = root->children[ch];
        if(root->endingword != ""){
            result.push_back(root->endingword);
            root->endingword = "";
        }

        char originalChar = board[r][c];
        board[r][c] = '#'; // denoting visited

        for(auto it : directions){
            int nr = r + it.first, nc = c + it.second;
            if(nr >= 0 and nc >= 0 and nr < board.size() and nc < board[0].size() 
            and board[nr][nc] != '#'){
                DFS(board, nr, nc, root, result);
            }
        }
        board[r][c] = originalChar;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node('\0');
        for(auto word : words){
            pushinTries(word, root);
        }
        vector<string> result;
        int m = board.size(), n = board[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                DFS(board, r, c, root, result);
            }
        }
        return result;
    }
};

int main() {

    return 0;
}