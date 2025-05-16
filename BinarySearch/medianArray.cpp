#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0, n = nums1.size() + nums2.size();
        while(i < nums1.size() and j < nums2.size()){
            if(nums1[i] < nums2[j]) res[k++] = nums1[i++];
            else res[k++] = nums2[j++];
        }
        while(i < nums1.size()) res[k++] = nums1[i++];
        while(j < nums2.size()) res[k++] = nums2[j++];
        if(n % 2 == 0) return (double)((res[n/2] + res[(n/2)-1])/2.0);
        else return (double) res[n/2];
    }
};

int main() {

    return 0;
}