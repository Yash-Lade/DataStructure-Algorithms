#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    // Write your code here.

    if(head == NULL || head->next == NULL) return head;

    Node* zeroNode = new Node(-1);
    Node* oneNode = new Node(-1);
    Node* twoNode = new Node(-1);

    Node *zero = zeroNode;
    Node *one = oneNode;
    Node *two = twoNode;

    Node *temp = head;

    while(temp!=NULL){

        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }

        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }

        else{
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneNode->next) ? oneNode->next: twoNode->next;
    one->next = twoNode->next;
    two->next = NULL;

    Node* newHead = zeroNode->next;
    delete zeroNode;
    delete oneNode;
    delete twoNode;
    
    return newHead;
}