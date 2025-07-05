#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> capitalHeap;
        priority_queue<int> profitHeap;

        int n = profits.size();
        for (int i = 0; i < n; i++) {
            capitalHeap.push({capital[i], profits[i]});
        }

        while (k--) {
            while (!capitalHeap.empty() && capitalHeap.top().first <= w) {
                profitHeap.push(capitalHeap.top().second);
                capitalHeap.pop();
            }

            if (profitHeap.empty()) break;
            w += profitHeap.top(); profitHeap.pop();
        }

        return w;
    }
};


int main() {

    return 0;
}