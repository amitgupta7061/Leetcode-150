#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // death -> live => 2, live -> death => 3
        vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                                             {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int liveCnt = 0, deathCnt = 0;
                for(auto it : directions){
                    int nRow = i + it.first, nCol = j + it.second;
                    if(nRow >= 0 and nCol >= 0 and nRow < m and nCol < n){
                        if(board[nRow][nCol] == 1 or board[nRow][nCol] == 3) liveCnt++;
                        else if(board[nRow][nCol] == 0 or board[nRow][nCol] == 2) deathCnt++;
                    }
                }
                if(board[i][j] == 1){
                    if(liveCnt < 2) board[i][j] = 3;
                    else if(liveCnt > 3) board[i][j] = 3;
                } else{
                    if(liveCnt == 3) board[i][j] = 2;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};


int main() {

    return 0;
}