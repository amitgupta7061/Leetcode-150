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

class BSTIterator {
public:
    stack<TreeNode*> st;
    void f(TreeNode* root){
        for(;root != NULL; st.push(root), root = root->left);
    }
    BSTIterator(TreeNode* root) {
        f(root);
    }
    
    int next() {
        TreeNode* node = st.top(); st.pop();
        f(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {

    return 0;
}