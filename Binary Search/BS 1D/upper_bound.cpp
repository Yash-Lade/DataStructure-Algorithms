#include<iostream>
#include<vector>
using namespace std;

// Upper bound - if arr[idx]> target
int upperBound(vector<int> arr, int n, int target){
    int left=0, right=n-1;
    int ans=n;

   while(left<=right){
        int mid= left+(right-left)/2;

        if(arr[mid]>target){
            ans=mid;
            right=mid-1;
        }
        else 
        left=mid+1;
    }
    return ans;
}

int main(){
    int n,no;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>no;
        arr.push_back(no);
    }

    cout<<"Enter the target: ";
    cin>>no;
    int ub= upperBound(arr, n, no);
    cout<<"The lower bound for given array is: "<<ub;
}