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
    ListNode* ReverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head, *prev = NULL;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = ReverseLL(head);
        ListNode* temp = head, *prev = NULL;
        int count = 1;
        while(temp){
            if(count == n){
                ListNode* el = temp;
                if(prev != NULL) prev->next = prev->next->next;
                else head = temp->next;
                delete el;
                break;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        head = ReverseLL(head);
        return head;
    }
};
