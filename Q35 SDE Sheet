/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool loop = false;
        while(slow && slow->next && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                loop = true;
                break;
            }
        }
        if(!loop) return NULL;
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
