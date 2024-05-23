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
    ListNode* doReverse(ListNode* node){
        ListNode* temp = NULL;
        while(node != NULL){
            ListNode* nex = node->next;
            node->next = temp;
            temp = node;
            node = nex;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        secondHalf = doReverse(secondHalf);

        ListNode* A = head;
        ListNode* B = secondHalf;

        while(A != NULL && B != NULL){
            ListNode* A_next = A->next;
            ListNode* B_next = B->next;

            A->next = B;
            B->next = A_next;

            A = A_next;
            B = B_next;
        }
    }
};