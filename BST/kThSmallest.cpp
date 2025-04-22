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
    void f(TreeNode* root, int &cnt, int &ans, int &k){
        if(!root) return;
        f(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val; return;
        }
        f(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        f(root, cnt, ans, k);
        return ans;
    }
};

int main() {

    return 0;
}