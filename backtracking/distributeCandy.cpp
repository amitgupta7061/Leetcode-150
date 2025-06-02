#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int n, int limit, int candidate, int &cnt){
        if(n == 0 and candidate == 4){
            cnt++; return;
        }
        for(int i = 0; i <= min(limit, n); i++){
            f(n-i, limit, candidate+1, cnt);
        }
    } 
    long long distributeCandies(int n, int limit) {
        int cnt = 0;
        f(n, limit, 1, cnt);
        return cnt;
    }
};

int main() {

    return 0;
}