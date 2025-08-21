#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data= data1;
        next= nullptr;
    }
};
// return Head of LL
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

int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp = head;
    while(temp!=nullptr){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main(){
    vector<int> arr= {1 ,2, 3, 4, 5};
    Node* head= convertArr(arr);
    Node* temp = head;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    // Length of LL
    cout<<"Lenth of LL is: "<<lengthOfLL(head);
}