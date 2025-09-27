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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == nullptr) return head;
        ListNode* temp = head;

        vector<int> arr;
        while(temp)
        {
             arr.push_back(temp -> val);
            temp = temp -> next;
        }

        reverse(arr.begin()+ left-1, arr.begin() + right);
        ListNode* newList = new ListNode(0);
        temp = newList;
        for(int i = 0 ; i < arr.size() ; i++){
            ListNode *newhead = new ListNode(arr[i]);
            temp -> next =newhead;
            temp = temp -> next ;
        }

        return newList -> next;
    }
};
