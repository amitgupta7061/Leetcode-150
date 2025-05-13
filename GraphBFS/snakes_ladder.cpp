#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), num = n * n, steps = 0;
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // even-indexed row: left to right
                for (int j = 0; j < n; ++j) {
                    map[num--] = {i, j};
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    map[num--] = {i, j};
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q; // {number, steps}
        q.push({1, 0});
        visited[map[1].first][map[1].second] = true;
        while(q.size()){
            auto [currNum, steps] = q.front(); q.pop();
            if(currNum == num) return steps;

            for(int i = 1; i <= 6; i++){
                int nextNum = currNum + i;
                if(nextNum > num) continue;
                auto [x, y] = map[nextNum];
                if(visited[x][y]) continue;

                visited[x][y] = true;

                if(board[x][y] != -1){
                    q.push({board[x][y], steps+1});
                }else{
                    q.push({nextNum, steps+1});
                }
            }
        }
        return -1;


    }
};
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), steps = 0, num = n * n;
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // even-indexed row: left to right
                for (int j = 0; j < n; ++j) {
                    map[num--] = {i, j};
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    map[num--] = {i, j};
                }
            }
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        q.push({1, steps});
        
        while(!q.empty()) {
            
            int N = q.size();
            while(N--) {
                auto [currNum, steps] = q.front(); q.pop();
                if(currNum == n*n) return steps;

                for(int k = 1; k <= 6; k++) {
                    if(currNum + k > n*n)break;
                    auto [r, c] = map[currNum + k];
                    if(visited[r][c] == true) continue;
                    visited[r][c] = true;
                    if(board[r][c] == -1) q.push({currNum + k, steps+1});
                    else q.push({board[r][c], steps+1});
                }
            }
        }
        
        return -1;
    }
};

int main() {

    return 0;
}