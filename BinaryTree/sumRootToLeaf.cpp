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
    void f(TreeNode* root, int num, int &sum){
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            sum += num;
            return;
        }
        f(root->left, num, sum);
        f(root->right, num, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        f(root, 0, sum);
        return sum;
    }
};

int main() {

    return 0;
}