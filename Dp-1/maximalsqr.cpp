#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<char>> &mat, int r, int c, int &maxi, vector<vector<int>> &dp){
        if(r >= mat.size() or c >= mat[0].size()) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int right  = f(mat, r, c+1, maxi, dp);
        int bottom = f(mat, r+1, c, maxi, dp);
        int diag   = f(mat, r+1, c+1, maxi, dp);


        if(mat[r][c] == '1'){
            int ans = 1 + min({right, bottom, diag});
            maxi = max(maxi, ans);
            return dp[r][c] = ans;
        } else {
            return dp[r][c] = 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        f(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
};

int main() {

    return 0;
}