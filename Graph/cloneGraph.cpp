#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    void DFS(Node* original, Node* clone, vector<Node*> &visited){
        for(auto neighbour : original->neighbors){
            if(!visited[neighbour->val]){
                Node* newNode = new Node(neighbour->val);
                visited[newNode->val] = newNode;
                clone->neighbors.push_back(newNode);
                DFS(neighbour, newNode, visited);
            } else {
                clone->neighbors.push_back(visited[neighbour->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> visited(110, NULL);
        Node* clone = new Node(node->val);
        visited[clone->val] = clone;
        DFS(node, clone, visited);
        return clone;
    }
};

int main() {

    return 0;
}