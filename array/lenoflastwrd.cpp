#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool getChar = false; 
        int firstCharIdx = -1, n = s.length(), i;
        for(i = n-1; i >= 0; i--){
            if(isalpha(s[i])){
                if(firstCharIdx == -1) firstCharIdx = i;
                getChar = true;
            }
            if(getChar and s[i] == ' ') return firstCharIdx - i;
        }
        return firstCharIdx - i;
    }
};


int main() {

    return 0;
}