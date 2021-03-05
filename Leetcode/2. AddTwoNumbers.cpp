class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        auto sum = l1->val + l2->val;
        auto carry = sum / 10;
        ListNode* head = new ListNode(sum % 10);
        ListNode* tail = head;
        l1 = l1->next;
        l2 = l2->next;

        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l1 = l1->next;
        }

        while(l2)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l2 = l2->next;
        }
        if(carry)
            tail->next = new ListNode(1);

        return head;
    }
    /*
    // 官方答案
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    */
};
