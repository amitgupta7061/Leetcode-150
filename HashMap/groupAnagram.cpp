#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            map[temp].push_back(it);
        }
        for(auto it : map){
            result.push_back(it.second);
        }
        return result;
    }
};

int main() {

    return 0;
}