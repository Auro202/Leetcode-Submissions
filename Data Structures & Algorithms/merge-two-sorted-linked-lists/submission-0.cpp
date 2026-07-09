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
private:
    void insert(ListNode* head, ListNode* pos1, ListNode* pos2){
        if(pos1){
            pos1->next = head;
            head->next = pos2;
        }else{
            head->next = pos2;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* temp1 = list1, *temp2 = list2, *prev = NULL, *ans = NULL;
        if(list1->val >= list2->val){
            ans = list2;
        }else{
            ans = list1;
        }
        while(temp2 && temp1){
            if(temp1->val >= temp2->val){
                ListNode* lol = temp2->next;
                insert(temp2, prev, temp1);
                prev = temp2;
                temp2 = lol;
            }else{
                prev = temp1;
                temp1 = temp1->next;
            }
        }
        if(temp2 != NULL && prev != NULL){
            prev->next = temp2;
        }
        return ans;
    }
};
