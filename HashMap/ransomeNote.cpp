#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> isavailable;
        for(auto it : magazine) isavailable[it]++;

        for(auto ch : ransomNote){
            if(!isavailable.count(ch)) return false;
            else {
                isavailable[ch] == 1 ? isavailable.erase(ch) : isavailable[ch]--;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}