class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                     // Calculate the new carry
            current->next = new ListNode(sum % 10); // Store the digit value
            current = current->next;              // Move pointer forward
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Clean up memory for the dummy node
        return result;
    }
};
