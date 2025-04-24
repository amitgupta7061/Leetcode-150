#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int m, int n){
        visited[r][c] = true;
        for(auto it : direction){
            int nr = r + it.first, nc = c + it.second;
            if(nr < 0 or nc < 0 or nr >= m or nc >= n or grid[nr][nc] == '0' or visited[nr][nc]) continue;
            DFS(grid, visited, nr, nc, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] and grid[i][j] == '1'){
                    cnt++; DFS(grid, visited, i, j, m, n);
                }
            }
        }
    }
};

int main() {

    return 0;
}