#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string s, vector<string> &t){
        if(s.size() != t.size()) return false;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i]; string temp = t[i];
            if(map1.count(ch) or map2.count(temp)){
                string str = map1[ch];
                if(str != temp or map2[str] != ch) return false;
            }
            map1[ch] = temp;
            map2[temp] = ch;
        }
        return true;
    }
    bool wordPattern(string pattern, string s) {
        vector<std::string> str;
        stringstream ss(s);
        string word;
        while (ss >> word) str.push_back(word);
        return f(pattern, str);
    }
};

int main() {

    return 0;
}