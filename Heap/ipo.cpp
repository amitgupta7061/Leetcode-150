#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < profits.size(); i++){
            pq.push({profits[i], capital[i]});
        }
        while(k--){
            vector<pair<int, int>> recover;
            while(pq.size()){
                int pr = pq.top().first, cp = pq.top().second; pq.pop();
                if(w >= cp){
                    w += pr; break;
                } else{
                    recover.push_back({pr, cp});
                }
            }
            for(auto it : recover) pq.push(it);
        }
        return w;
    }
};

int main() {

    return 0;
}