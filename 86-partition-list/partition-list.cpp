/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode leftDummy(-1); 
        ListNode rightDummy(-1); 
        ListNode *left = &leftDummy; 
        ListNode *right = &rightDummy;
        ListNode *temp = head;
        while(temp!=nullptr){
            if(temp->val<x){
                left->next = temp; 
                left = temp; 
                temp = temp->next;
            }
            else{
                right->next = temp; 
                right = temp; 
                temp = temp->next;
            }
        }
        left->next = rightDummy.next; 
        right->next = nullptr; 
        return leftDummy.next;
    }
};