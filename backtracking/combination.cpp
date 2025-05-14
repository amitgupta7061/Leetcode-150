#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int n, int k, vector<int> &temp, vector<vector<int>> &result, int ind = 1){
        if(temp.size() == k){
            result.push_back(temp); return;
        }
        for(int i = ind; i <= n; i++){
            temp.push_back(i);
            f(n, k, temp, result, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        f(n, k, temp, result);
        return result;
    }
};

int main() {

    return 0;
}