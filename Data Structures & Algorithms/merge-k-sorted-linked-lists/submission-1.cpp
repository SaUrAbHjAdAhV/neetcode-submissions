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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }

        struct compare{
            bool operator()(ListNode* &a, ListNode* &b){
                return a->val > b->val;
            }
        };

        priority_queue <ListNode*, vector<ListNode*>, compare> minHeap;

        for(auto &list : lists){
            if(list == nullptr){
                continue;
            }
            minHeap.push(list);
        }

        ListNode* dummyhead = new ListNode();
        ListNode* temp = dummyhead;

        while(!minHeap.empty()){
            ListNode* cur = minHeap.top();
            minHeap.pop();

            temp->next = cur;

            if(cur->next != nullptr){
                minHeap.push(cur->next);
            }

            temp = cur;
        }

        ListNode* head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
