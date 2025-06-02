#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int num1 = 0, num2 = 0, sum = 0;
        for(auto it : a) num1 += (it - '0')*2;
        for(auto it : b) num2 += (it - '0')*2;
        sum = num1 + num2;
        string result = "";
        while (sum > 0) {
            result = (sum % 2 == 0 ? "0" : "1") + result;
            sum /= 2;
        }
        return result;
    }
};

int main() {

    return 0;
}