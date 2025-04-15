#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        unordered_map<Node*, Node*> randomp;
        Node * newHead = NULL;
        Node* temp1 = head;
        Node* temp2 = newHead; 

        while(temp1){
            Node* a = new Node(temp1->val);
            if(newHead == NULL){
                newHead = a; temp2 = a;
                map[temp1] = temp2;
            } else{
                temp2->next = a;
                temp2 = temp2->next;
                map[temp1] = temp2;
            }
            if(temp1->random) randomp[temp1] = temp1->random;
            temp1 = temp1->next;
        }


        for(auto it : map){
            Node* f_node = it.first; Node* s_node = it.second;
            if(f_node->random){
                s_node->random = map[randomp[f_node]];
            }
        }
        return newHead;
    }
};
    

int main() {

    return 0;
}