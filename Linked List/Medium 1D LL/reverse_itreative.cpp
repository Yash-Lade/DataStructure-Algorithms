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

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reverse(Node* head){

    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

int main(){
    vector<int> arr= {1 ,2, 3, 4, 5};
    Node* head= convertArr(arr);

    head = reverse(head);

    print(head);
}