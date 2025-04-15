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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(100);
        ListNode* gret = new ListNode(100);
        ListNode* temp1 = less; ListNode* temp2 = gret; ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                temp1->next = temp; temp1 = temp1->next;
            } else{
                temp2->next = temp; temp2 = temp2->next;  
            }
            temp = temp->next;
        }
        temp1->next = gret->next; temp2->next = NULL;
        return less->next; 
    }
};

int main() {

    return 0;
}