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
    int len;
    ListNode* h;
    Solution(ListNode* head) {
        ListNode* curr = head;
        h = head;
        len = 0;
        while(curr != nullptr) {
            len++;
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int node = rand() % len;
        ListNode* curr = h;
        while(node > 0) {
            curr = curr->next;
            node--;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */