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
            agla = curr->next; curr->next = prev;
            prev = curr; curr = agla;
        }
        return prev;
    }
    ListNode* searchTargetNode(ListNode* head, int k){
        ListNode* temp = head;
        for(int i = 1; i < k && temp; i++) temp = temp->next;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; ListNode* prev = NULL;
        while(temp){
            ListNode* kThNode = searchTargetNode(temp, k);
            if(kThNode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* after = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedLIst(temp);
            if(temp == head) head = kThNode;
            else prev->next = kThNode;
            prev = temp; temp = after;
        }
        return head;
    }
};


int main() {

    return 0;
}