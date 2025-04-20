#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    class Node{
    public:
        int key, val;
        Node* next; Node* prev;
        Node(int key, int val){
            this->key = key; this->val = val;
            this->next = NULL; this->prev = NULL;
        }
    };
    int capacity, size;
    unordered_map<int, Node*> cache;
    Node* head = NULL; Node* tail = NULL;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(Node* node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    Node* removeTail(){
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            addToHead(node);
        } else{
            Node* node = new Node(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if(size > capacity){
                Node* node = removeTail();
                cache.erase(node->key);
                delete node;
                size--;
            }
        }
    }
};


int main() {

    return 0;
}