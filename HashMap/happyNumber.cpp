#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int num){
        int sum = 0;
        while(num != 0){
            int rem = num % 10;
            sum += (rem * rem);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, int> map;
        while(n != 1){
            if(map.count(n)) return false;
            map[n]++;
            n = f(n);
        }
        return true;
    }
};

int main() {

    Solution sol;
    cout<<sol.isHappy(2);
    return 0;
}