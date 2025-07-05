#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> store(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        string choice = "ACGT";

        while(q.size()){
            auto [currGene, steps] = q.front(); q.pop();
            if(currGene == endGene) return steps;
            for(int i = 0; i < currGene.size(); i++){
                char originalChar = currGene[i];
                for(char ch : choice){
                    currGene[i] = ch;
                    if(store.count(currGene)) q.push({currGene, steps+1});
                    store.erase(currGene);
                }
                currGene[i] = originalChar;
            }
        }
        
        return -1;
    }
};

int main() {

    return 0;
}