#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reversell(ListNode* head){
        if(!head or !head -> next){
            return head;
        }
        ListNode* temp = reversell(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reversell(l1), l2 = reversell(l2);
        int sum = 0, carry = 0;
        ListNode* res = new ListNode();
        while(l1 != NULL or l2 != NULL){
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            res -> val = sum%10;
            carry = sum/10;
            ListNode* temp = new ListNode(carry);
            temp -> next = res;
            res = temp;
            sum = carry;
        }
        return carry == 0 ? res -> next : res;
    }
};