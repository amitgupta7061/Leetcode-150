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
    int f(TreeNode* root, int max_sum){
        if(!root) return 0;
        int left = max(0, f(root->left, max_sum));
        int rght = max(0, f(root->right, max_sum));
        max_sum = max(max_sum, root->val + left + rght);
        return root->val + max(left, rght);
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        f(root, max_sum);
        return max_sum;
    }
};

int main() {

    return 0;
}