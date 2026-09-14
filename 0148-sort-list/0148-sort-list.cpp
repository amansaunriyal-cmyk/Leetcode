class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // 1. Base case
        if (head == NULL || head->next == NULL)
            return head;

        // 2. Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 3. Divide into two lists
        ListNode* right = slow->next;
        slow->next = NULL;

        // 4. Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // 5. Merge sorted halves
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left != NULL)
            temp->next = left;

        if (right != NULL)
            temp->next = right;

        return dummy.next;
    }
};