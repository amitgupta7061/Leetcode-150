#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 5, sum = 0;
        while(n / num){
            sum += (n / num);
            num *= 5;
        }
        return sum;
    }
};

int main() {

    return 0;
}