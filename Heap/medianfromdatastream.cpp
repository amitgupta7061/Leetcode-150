#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    MedianFinder() {
        
    }
    
    void balanceHeap(){
        if((minHeap.size() - maxHeap.size()) > 1){
            while((minHeap.size() - maxHeap.size()) > 1){
                maxHeap.push(minHeap.top()); 
                minHeap.pop();
            }
        }
        if((maxHeap.size() - minHeap.size()) > 1){
            while((maxHeap.size() - minHeap.size()) > 1){
                minHeap.push(maxHeap.top()); 
                maxHeap.pop();
            }
        }
    }

    void addNum(int num) {
        if(maxHeap.empty() or maxHeap.top() >= num){
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balanceHeap();
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) 
            return (maxHeap.top() + minHeap.top()) / 2;
        else if(minHeap.size() > maxHeap.size())
            return minHeap.top();
        else return 0;
    }
};

int main() {

    return 0;
}