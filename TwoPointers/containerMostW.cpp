#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0;
        while(i < j){
            result = max(result, min(height[i], height[j]) * (j-i));
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return result;
    }
};

int main() {

    return 0;
}