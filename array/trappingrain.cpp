#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0, rightmax = 0, maxi = height[0], ind = 0;
        for(int i = 1; i < height.size(); i++){
            if(height[i] > maxi){
                maxi = height[i]; ind = i;
            }
        }
        int result = 0;
        for(int i = 0; i <= ind; i++){
            if(height[i] < leftmax) result += leftmax - height[i];
            else leftmax = height[i];
        }
        for(int i = height.size()-1; i >= ind; i--){
            if(height[i] < rightmax) result += rightmax - height[i];
            else rightmax = height[i];
        }
        return result;
    }
};

int main() {

    return 0;
}