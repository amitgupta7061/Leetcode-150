#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> grid;
    bool canPlace(int row, int col, int n){
        for(int i = row-1; i >= 0; i--)  // column check
            if(grid[i][col] == "Q") return false;
        for(int i = row-1, j = col-1; i >=0 and j >= 0; i--, j--) // left diagonal 
            if(grid[i][j] == "Q") return false;
        for(int i = row-1, j = col + 1; i >= 0 and j < n ; i--, j++) // right diagonal
            if(grid[i][j] == "Q") return false;
        return true;
    }
    void f(int row, int n, int &cnt){
        if(row == n) cnt++;
        for(int col = 0; col < n; col++){
            if(canPlace(row,col,n)){
                grid[row][col] = "Q";
                f(row+1,n,cnt);
                grid[row][col] = ".";
            }
        }
    }
    int totalNQueens(int n) {
        grid.clear();
        grid.resize(n,vector<string>(n,"."));
        int cnt = 0;
        f(0, n,cnt);
        return cnt;
    }
};

int main() {

    return 0;
}