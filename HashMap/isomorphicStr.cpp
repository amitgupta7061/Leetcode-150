#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string s, string t){
        if(s.length() != t.length()) return false;
        unordered_map<char, char> mapping;
        for(int i = 0; i < s.length(); i++){
            if(mapping.count(s[i])){
                if(mapping[s[i]] != t[i]) return false;
            } else{
                mapping[s[i]] = t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return f(s, t) and f(t, s);
    }
};

int main() {

    return 0;
}