#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result = "";
        while(ss >> word){
            if(result.empty()) result = word;
            else result = " " + word + result;
        }
        return result;
    }
};


int main() {

    return 0;
}