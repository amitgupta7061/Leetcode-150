#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(int x) {
        int palindrome = x, rev = 0;
        if(x < 0) return false;
        while(palindrome != 0){
            int reminder = palindrome % 10;
            rev = rev * 10 + reminder;
            palindrome /= 10;
        }
        return rev == x;
    }
};

int main() {

    return 0;
}