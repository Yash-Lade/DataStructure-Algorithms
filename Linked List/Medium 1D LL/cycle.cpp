#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force - using Hashing

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;
        while(temp!=nullptr){
            if(mpp.find(temp)!=mpp.end())   // i.e. if temp is already in map then there's loop
            return true;

            mpp[temp]=1;
            temp = temp->next;
        }
        return false;
    }
};  

// Optimal - using Tortoise Hare method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};