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
};

int main(){
    vector<int> arr= {1 ,2, 3, 4, 5};

    Node y= Node(arr[1], nullptr);
    Node* ptr=new Node(arr[0], nullptr);

    cout<<ptr<<endl; // print the pointer to mem loc
    cout<<y.data; // print the data
}