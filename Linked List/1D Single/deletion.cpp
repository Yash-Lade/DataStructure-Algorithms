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

Node* deleteHead(Node* head){       // delete Start
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){       // delete End
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;

    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr; 

    return head;
}

Node* deleteK(Node* head, int target){  // delete at specific position
    if(head==NULL) return head;
    if(target==1){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev=NULL;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==target){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
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
int main(){
    vector<int> arr= {1 ,2, 3, 4, 5};
    Node* head= convertArr(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);

    int k;
    cout<<"Enter element to delete: "; cin>>k;
    head = deleteK(head, k);
    print(head);
}