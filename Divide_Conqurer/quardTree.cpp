#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    bool isSameElement(vector<vector<int>> &grid, int r, int c, int n){
        int val = grid[r][c];
        for(int i = r; i < r + n; i++){
            for(int j = c; j < c + n; j++){
                if(grid[i][j] != val) return false;
            }
        }
        return true;
    }
    Node* f(vector<vector<int>> &grid, int r, int c, int n){
        if(isSameElement(grid, r, c, n))
            return new Node(grid[r][c], true);

        Node* root = new Node(1, false);
        root->topLeft = f(grid, r, c, n/2);
        root->topRight = f(grid, r, c+n/2, n/2);
        root->bottomLeft = f(grid, r+n/2, c, n/2);
        root->bottomRight = f(grid, r+n/2, c+n/2, n/2); 
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return f(grid, 0, 0, grid.size());
    }
};

int main() {

    return 0;
}