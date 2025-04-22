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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> result;
        queue<TreeNode*> q; q.push(root);
        while(q.size()){
            int n = q.size(); double sum = 0;
            for(int i = 1; i <= n; i++){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double temp = sum / (n * 1.0);
            result.push_back(temp);
        }
        return result;
    }
};

int main() {

    return 0;
}