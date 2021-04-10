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
#include <queue>
class Solution {
public:
    struct Node
    {
        int val;
        ListNode* ptr;
        inline
        bool operator<(const Node& rhs) const
        {
            return val > rhs.val;
        }
    };
    priority_queue<Node>que;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(const auto& i :lists)
            if(i != nullptr)
                que.push({i->val, i});
        ListNode head, *tail = &head;
        while(!que.empty())
        {
            auto f = que.top();
            que.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if(f.ptr->next)
                que.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};