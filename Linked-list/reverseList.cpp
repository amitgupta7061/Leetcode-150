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
    ListNode* reverseLinkedLIst(ListNode* head){
        ListNode* curr = head; ListNode* prev = NULL; ListNode* agla = NULL;
        while(curr){
            agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int rght) {
        if(left == rght) return head;
        ListNode* p = NULL; ListNode* q = NULL;
        ListNode* r = NULL; ListNode* s = NULL;
        int cnt = 1; ListNode* temp = head;
        while(temp){
            if(cnt == left - 1) p = temp;
            else if(cnt == left) q = temp;
            else if(cnt == rght) r = temp;
            else if(cnt == rght + 1) s = temp;
            temp = temp->next;
            cnt++;
        }

        if(p != NULL) p->next = NULL;
        r->next = NULL;
        r = reverseLinkedLIst(q);
        if(p != NULL) p->next = r;
        q->next = s;
        if(p != NULL) return head;
        return r;
    }
};
 

int main() {

    return 0;
}