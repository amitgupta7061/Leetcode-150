#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    bool f(vector<vector<char>>& board, int r, int c, int ind, vector<vector<bool>> &visited, string &word){
        if(ind == word.size()) return true;
        visited[r][c] = true;
        
        for(auto it : direction){
            int nr = r + it.first, nc = c + it.second;
            if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size() || visited[nr][nc]
               || board[nr][nc] != word[ind]) continue;
            
            if(f(board, nr, nc, ind + 1, visited, word)) return true;
        }
        
        visited[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(f(board, i, j, 1, visited, word)) return true;
                }
            }
        }
        return false;
    }
};


int main() {

    return 0;
}