#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(int ind, vector<string>& words, unordered_set<string>& result) {
        if (ind == words.size()) {
            string concat = "";
            for (const auto& w : words) concat += w;
            result.insert(concat);
            return;
        }

        for (int i = ind; i < words.size(); i++) {
            swap(words[i], words[ind]);
            permute(ind + 1, words, result);
            swap(words[i], words[ind]);
        }
    }

    unordered_set<string> f(vector<string>& words) {
        unordered_set<string> result;
        permute(0, words, result);
        return result;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<string> dict = f(words);
        vector<int> result;
        
        int k = (*dict.begin()).length();

        for(int i = 0; i < s.size() - k + 1; i++){
            if(dict.count(s.substr(i, i + k))) result.push_back(i);
        }
        return result;
    }
};

int main() {

    return 0;
}