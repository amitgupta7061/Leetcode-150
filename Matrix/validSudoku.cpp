#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> visited(10, -1);
            for(auto it : board[i]){
                if(it != '.' and visited[it - '0'] != -1) return false;
                if(it != '.') visited[it - '0'] = 1;
            }
        }
        for(int i = 0; i < 9; i++){
            vector<int> visited(10, -1);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.' and visited[board[j][i] - '0'] != -1) return false;
                if(board[j][i] != '.') visited[board[j][i] - '0'] = 1;
            }
        }
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                vector<int> visited(10, -1);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = blockRow * 3 + i;
                        int col = blockCol * 3 + j;
                        if (board[row][col] == '.') continue;
                        if (visited[board[row][col] - '0'] != -1) return false;
                        visited[board[row][col] - '0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};


int main() {

    return 0;
}