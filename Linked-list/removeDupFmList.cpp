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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = new ListNode(100);
        ListNode* temp1 = head; ListNode* temp2 = result;

        while(temp1){
            int cnt = 0, val = temp1->val;
            ListNode* curr = temp1;
            while(temp1 and temp1->val == val){
                cnt++; temp1 = temp1->next;
            }
            cout<<cnt<<" ";
            if(cnt == 1){
                temp2->next = curr; temp2 = temp2->next; temp2->next = NULL;
            }
        }

        return result->next;
    }
};


int main() {

    return 0;
}