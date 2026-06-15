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
        struct compare{
            bool operator()(ListNode &a, ListNode &b){
                return a.val > b.val;
            }
        };

        priority_queue <ListNode, vector<ListNode>, compare> minHeap;

        for(auto &list : lists){
            if(lists.empty()){
                break;
            }
            if(list == nullptr){
                continue;
            }
            minHeap.push({
                list->val,
                list->next
            });
        }

        ListNode* dummyhead = new ListNode();
        ListNode* temp = dummyhead;

        while(!minHeap.empty()){
            ListNode* cur = new ListNode(minHeap.top());
            minHeap.pop();

            temp->next = cur;

            if(cur->next != nullptr){
                minHeap.push({
                    cur->next->val,
                    cur->next->next
                });
            }

            temp = cur;
        }

        ListNode* head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
