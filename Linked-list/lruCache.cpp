#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    vector<int> memory;
    unordered_map<int, int> key_val;
    int ind = 0;
    LRUCache(int capacity) {
        memory.resize(capacity);
    }
    
    int get(int key) {
        return key_val[key];
    }
    
    void put(int key, int value) {
        if(ind >= memory.size()){
            key_val.erase(memory[--ind]);
            memory[ind++] = key;
            key_val[key] = value;
        } else{
            memory[ind++] = key;
            key_val[key] = value;
        }
    }
};

int main() {

    return 0;
}