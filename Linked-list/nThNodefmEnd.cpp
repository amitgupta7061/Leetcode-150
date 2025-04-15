#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) { this->val = val; }
};

class Solution {
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head; ListNode* fast = head;
        if(head == NULL || head->next == NULL) return NULL;
        while(n != 0 && fast != NULL){
            fast = fast->next; n--;
        }
        if(fast == NULL) return slow->next;

        while(fast->next != NULL){
            slow = slow->next; fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


int main() {

    return 0;
}

// git add .
// git commit -m "linked -list"
// git push -u origin main