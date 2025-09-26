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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while(temp){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        int dec = 0;
        int n  = arr.size();

        for(int i = 0 ; i < n ; i++)
            {
                dec = dec * 2 + arr[i];
            }

        return dec;
    }
};
