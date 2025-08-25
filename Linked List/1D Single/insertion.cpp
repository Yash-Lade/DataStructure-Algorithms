#include<iostream>
#include<vector>
using namespace std;

struct  Node
{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

void print(Node* head);
Node* convertArr(vector<int> &arr);


Node* insertHead(Node* head, int val){          // insert at the beginning
    Node* temp = new Node(val, head);   
}

Node* insertTail(Node* head, int val){          // insert at the end
    // if no List exist     
    if(head == NULL) 
    return head = new Node(val);

    Node* ptr = new Node(val, nullptr);
    Node* temp = head;
    while(temp->next!=NULL) temp = temp->next;

    temp->next = ptr;
    return head;
}

Node* insertAtK(Node* head, int val, int k){    // insert at specific position
    if(k==1)    
    {
        Node* temp = new Node(val, head);
    }
    
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){
            Node* ptr = new Node(val, temp->next);
            temp->next = ptr;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeX(Node* head, int val, int x){ // Insert element before the x position
    if(head  == NULL) return NULL;

    if(head->data == x) return new Node(val, head);

    Node* temp = head;

    while(temp!=NULL){
        
        if(temp->next->data == x){
            Node* ptr = new Node(val, temp->next);
            temp->next = ptr;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr= {1 ,2, 3, 4, 5};
    Node* head= convertArr(arr);

    int val;
    cout<<"Enter element to add: "; cin>>val;

    // head = insertHead(head, val);
    // head = insertTail(head, val);
    int pos;
    // cout<<"Enter the position of insertion: "; cin>>pos;
    // head = insertAtK(head, val, pos);
    cout<<"Enter the element before which you wanna insert: "; cin>>pos;
    head = insertBeforeX(head, val, pos);
    print(head);
}


Node* convertArr(vector<int> &arr){ 
    Node* head = new Node(arr[0]);
    Node* ptr= head;

    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}