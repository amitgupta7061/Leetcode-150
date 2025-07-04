#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[j][0] - points[i][0], y1 = points[j][1] - points[i][1];
                int cnt = 0;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    int x2 = points[k][0] - points[i][0], y2 = points[k][1] - points[i][1];
                    if(x1 * y2 == y1 * x2) cnt++;
                }
                result = max(result, cnt + 2);
            }
        }
        return n == 1 ? 1 : result;
    }
};


int main() {

    return 0;
}