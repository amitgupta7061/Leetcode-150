#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(string &digits, int ind, string &str, vector<string> &result, vector<string> &map){
        if(ind == digits.length()){
            result.push_back(str);
            return;
        }
        int index = digits[ind] - '0';
        string s = map[index];
        for(int i = 0; i < s.size(); i++){
            str.push_back(s[i]);
            f(digits, ind+1, str,result,map);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string str = "";
        f(digits, 0, str, result, map);
        return result;
    }
};

int main() {

    return 0;
}