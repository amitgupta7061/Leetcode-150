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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fisrt = new ListNode(100);
        ListNode* temp1 = fisrt;
        ListNode* temp3 = list1;
        ListNode* temp4 = list2;

        while(temp3 and temp4){
            if(temp3->val <= temp4->val){
                temp1->next = temp3; 
                temp1 = temp1->next;
                temp3 = temp3->next;
            } else{
                temp1->next = temp4; 
                temp1 = temp1->next;
                temp4 = temp4->next;
            }
        }
        while(temp3){
            temp1->next = temp3; 
            temp1 = temp1->next;
            temp3 = temp3->next; 
        }
        while(temp4){
            temp1->next = temp4; 
            temp1 = temp1->next;
            temp4 = temp4->next; 
        }
        return temp1->next;
    }
};


int main() {

    return 0;
}