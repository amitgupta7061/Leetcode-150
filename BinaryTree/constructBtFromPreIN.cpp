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
    TreeNode* f(vector<int> &pre, vector<int> &in, int str, int end, int &ind){
        if(str > end) return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int i = str;
        while(i <= end){
            if(pre[ind] == in[i]) break;
            i++;
        }
        ind++;
        root->left  = f(pre, in, str, i-1, ind);
        root->right = f(pre, in, i+1, end, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0, n = preorder.size();
        return f(preorder, inorder, 0, n - 1, index);
    }
};


int main() {

    return 0;
}