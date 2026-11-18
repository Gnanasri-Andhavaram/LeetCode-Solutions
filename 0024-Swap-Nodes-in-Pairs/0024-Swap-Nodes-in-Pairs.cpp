class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* current = &dummyHead;

        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            first->next = second->next;
            second->next = first;
            current->next = second;

            current = first;
        }

        return dummyHead.next;
    }
};
