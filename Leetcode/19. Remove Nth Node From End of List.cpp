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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (auto p = head; p; p = p->next)
            len++ ;
        auto dummy = new ListNode(0, head), p = dummy;
        for (int i = 1; i < len - n + 1; i ++ ) p = p->next;        //遍历到倒数第n个节点
        p->next = p->next->next;                                //跳过该节点

        return dummy->next;
    }
};