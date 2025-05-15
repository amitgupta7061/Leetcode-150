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
    ListNode* sortList(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = mergeTwoLists(a,b);

        return c;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* list3 = new ListNode(100);
        ListNode* temp3 = list3;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp3 = temp1;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }
        if(temp1!=NULL) temp3->next = temp1;
        if(temp2!=NULL) temp3->next = temp2;
        return list3->next;
    }
};

int main() {

    return 0;
}