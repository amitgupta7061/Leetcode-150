#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp); 
        int last_endTime = points[0][1];
        int n = points.size(), cnt = 0;
        for(int i = 1; i < n; i++){
            if(points[i][0] <= last_endTime){
                cnt++;
            }
            else{
                last_endTime = points[i][1];
            }
        }
        return n - cnt;
    }
};

int main() {

    return 0;
}