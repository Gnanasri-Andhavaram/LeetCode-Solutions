class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        current->next = head;
        k = k % length;
        int stepsToNewHead = length - k;

        for (int i = 0; i < stepsToNewHead; i++) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;

        return newHead;
    }
};
