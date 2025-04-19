#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(!isalpha(s[i]) and !isdigit(s[i])) i++;
            else if(!isalpha(s[j]) and !isdigit(s[j])) j--;
            else {
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++; j--;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}