#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> directoryNames;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!directoryNames.empty()) {
                    directoryNames.pop_back();
                }
            } else {
                directoryNames.push_back(token);
            }
        }
        if (directoryNames.empty()) {
            return "/";
        }
        string result;
        for (const auto& dirName : directoryNames) {
            result += "/" + dirName;
        }
        return result;
    }
};

int main() {

    return 0;
}