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
    long long maxInTree(TreeNode* root){
        if(root == NULL) return LLONG_MIN;
        return max((long long)root->val,max(maxInTree(root->left),maxInTree(root->right)));
    }
    long long minInTree(TreeNode* root){
        if(root == NULL) return LLONG_MAX;
        return min((long long)root->val,min(minInTree(root->left),minInTree(root->right)));
    }
    bool isValidBST(TreeNode* root){
        if(root==NULL) return true;
        else if((long long)root->val <= maxInTree(root->left)) return false;
        else if((long long)root->val >= minInTree(root->right)) return false;
        else return isValidBST(root->left) && isValidBST(root->right);
    }
};

int main() {

    return 0;
}