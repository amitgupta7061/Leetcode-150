#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(not head or not head->next) return head;
        int cnt = 1; ListNode* node = head;
        while(node->next){
            cnt++; node = node->next;
        }
        k = k % cnt; ListNode* temp = head;
        for(int i = 0; i < cnt - k - 1; i++){
            temp = temp->next;
        }
        node->next = head; head = temp->next;
        temp->next = NULL; return head;
    }
};

int main() {

    return 0;
}