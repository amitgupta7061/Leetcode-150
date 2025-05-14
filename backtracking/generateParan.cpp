#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int n, string &s, int cnt, vector<string> &result){
        if(cnt < 0 or cnt > n) return;
        if(s.size() == n*2){
            if(cnt == 0) result.push_back(s);
            return;
        }
        s.push_back('(');
        f(n, s, cnt+1, result);
        s.pop_back();
        s.push_back(')');
        f(n, s, cnt-1, result);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        f(n, s, 0, result);
        return result;
    }
};

int main() {

    return 0;
}