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
    void insert(ListNode* head, ListNode* pos1, ListNode* pos2){
        if(pos1){
            pos1->next = head;
        }
        head->next = pos2;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        if(list2 != NULL && list2->next != NULL){
            ListNode* temp = list2, *prev = NULL, *front = list2->next;
            while(temp){
                front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            list2 = prev;
        }
        ListNode* list1 = head;
        while(list2){
            ListNode* temp = list2->next;
            insert(list2, list1, list1->next);
            list2 = temp;
            list1 = list1->next->next;
        } 
    }
};
