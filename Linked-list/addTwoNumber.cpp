#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(100);
        ListNode* temp = head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL && temp2 != NULL){
            temp1->val += temp2->val;
            temp->next =  temp1;
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 != NULL) temp->next = temp1;
        if(temp2 != NULL) temp->next = temp2;
        head = head->next;
        temp = head;
        int carry = 0;
        ListNode* x = NULL;
        while(temp != NULL){
            temp->val += carry;
            carry = 0;
            if(temp->val >= 10){
                int a = temp->val % 10;
                temp->val /= 10;
                int b = temp->val % 10;
                temp->val = a;
                carry = b;
            }
            if(temp->next == NULL) x = temp;
            temp = temp->next;
        }
        if(carry!=0){
                ListNode* a = new ListNode(carry);
                x->next = a;
        }
        return head;
    }
};

int main() {

    return 0;
}