#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()) return false;
        int i = 0, j = 0, m = s.length(), n = t.length();

        while(i < m and j < n){
            if(s[i] == t[j]) i++;
            j++;
        }
        return i >= m;
    }
};

int main() {

    return 0;
}