#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makestringequalpart(string &str, int width) {
        vector<string> words;
        stringstream ss(str);
        string word;

        while (ss >> word) words.push_back(word);

        int total_chars = 0;
        for (auto &w : words) total_chars += w.size();

        int total_spaces = width - total_chars;
        int gaps = words.size() - 1;

        if (gaps == 0) {
            str = words[0] + string(total_spaces, ' ');
            return;
        }

        int even_space = total_spaces / gaps;
        int extra_space = total_spaces % gaps;

        string result = "";
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < gaps) {
                result += string(even_space + (i < extra_space ? 1 : 0), ' ');
            }
        }

        str = result;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int currlength = 0;
        string currstr = "";
        for(auto &str : words){
            if(currlength == 0){
                currstr += str;
                currlength = str.length();
            } else if(currlength + 1 + str.length() <= maxWidth){
                currstr += (" " + str);
                currlength += (str.length() + 1);
            } else {
                makestringequalpart(currstr, maxWidth);
                result.push_back(currstr);
                currstr = str;
                currlength = str.length();
            }
        }
        while(currstr.size() != maxWidth){
            currstr += " ";
        }
        result.push_back(currstr);
        return result;
    }
};

int main() {

    return 0;
}