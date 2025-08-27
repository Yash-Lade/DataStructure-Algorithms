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

Node* deleteHead(Node* head){

    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){                               // first tail of back = null
                                                            // prev of next = null
    if(head == NULL || head->next == NULL) return NULL;     // free tail

    Node* tail = head;
    
    while(tail->next!= NULL){
        tail = tail->next;
    }
    
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteK(Node  *head, int k){
    if(head == NULL) return NULL; 

    Node* temp = head;
    int cnt = 0;
    while(temp!= NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    // if we don't have a previous and front i.e. List has single element
    if(prev == NULL && front == NULL){
        delete temp;
        return nullptr;
    }
    // if k is the first node
    else if(prev == NULL)   {   
        return deleteHead(head); 
    }
    // if k is last node
    else if(front == NULL){
        return deleteTail(head);  
    }
    // else we are in between

    prev->next = front;
    front->back = prev;

    temp->next= nullptr;
    temp->back= nullptr;
    delete temp;

    return head;
}

// Delete the given node -> considering given note is except the head/first
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    // only one edge case i.e. given node is last means no front
    if(front == NULL)
    {
        prev->next = NULL;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArrtoDLL(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);
    int pos;
    cout<<"Enter the position: "; cin>>pos;
    head = deleteK(head, pos);
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