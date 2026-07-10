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
    void insert(ListNode* head, ListNode* pos1, ListNode* pos2){
        if(pos1){
            pos1->next = head;
        }
        head->next = pos2;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* ans = NULL, *temp1 = list1, *temp2 = list2, *prev = NULL;
        if(list1->val >= list2->val){
            ans = list2;
        }else{
            ans = list1;
        }
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val >= temp2->val){
                ListNode* temp = temp2->next;
                insert(temp2, prev, temp1);
                prev = temp2;
                temp2 = temp;
            }else{
                prev = temp1;
                temp1 = temp1->next;
            }
        }
        if(temp2 != NULL){
            prev->next = temp2;
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = (lists.size() > 0) ? lists[0] : NULL;
        for(int i = 1; i < lists.size(); i++){
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};
