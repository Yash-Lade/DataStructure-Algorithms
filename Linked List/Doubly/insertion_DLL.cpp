#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head);
Node* convertArrtoDLL(vector<int>& arr);

Node* insertHead(Node* head, int val){

    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node* insertTail(Node* head, int val){
    Node* temp = head;

    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* tail = new Node(val, nullptr, temp);
    temp->next = tail;
    
    return head;
}   

Node* insertBeforeTail(Node* head, int val){

    if(head->next == NULL) return insertHead(head, val);

    Node* temp = head;

    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    
    return head;
}   

Node* insertBeforeK(Node* head, int val, int k){

    if(k == 1) return insertHead(head, val);

    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){     // given node won't ever be Head

    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

// here all insertion would be before i.e. - before head, before tail, before k, before given node
int main(){

    vector<int> arr = {10,21,32,43,54};
    Node* head = convertArrtoDLL(arr);
    int val;
    cout<<"Enter the value to insert: "; cin>>val;
    // head = inserHead(head, val);
    // head = insertTail(head, val);
    // head = insertBeforeTail(head, val);
    // int pos;
    // cout<<"Enter the position: "; cin>>pos;
    // head = insertBeforeK(head, val, pos);

    insertBeforeNode(head->next->next, val);
    print(head);

    return 0;
}


Node* convertArrtoDLL(vector<int>& arr){

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}