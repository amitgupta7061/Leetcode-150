#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void f(TreeNode* root, int &min_diff, int &prev){
        if(!root) return;
        f(root->left, min_diff, prev);
        if(prev != -1) min_diff = min(min_diff, root->val - prev);
        prev = root->val;
        f(root->right, min_diff, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX, prev = -1;
        f(root, min_diff, prev);
        return min_diff;
    }
};

int main() {

    return 0;
}