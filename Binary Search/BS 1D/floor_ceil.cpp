#include<iostream>
#include<vector>
using namespace std;

// floor- largest element in array <= target
int floor(int arr[], int n, int target){
    int left=0, right=n-1;
    int ans=n;

    while(left<=right){
        int mid= left+(right-left)/2;

        if(arr[mid]<=target){
            ans=arr[mid];
            left=mid+1;
        }
        else 
        right=mid-1;
    }
    return ans;
}

// ceil- smallest no. in array >= target
int ceil(int arr[], int n, int target){
    // to find ceil we ultimately have to find lower bound

    int left=0, right=n-1;
    int ans=n;

    while(left<=right){
        int mid= left+(right-left)/2;

        if(arr[mid]>=target){
            ans=arr[mid];
            right=mid-1;
        }
        else 
        left=mid+1;
    }
    return ans;
}

int main(){
    int n, x;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Enter the target element: ";
    cin>>x;
    int flr=floor(arr,n,x);
    int cl =ceil(arr,n,x);
    cout<<"The floor is: "<<flr<<" and the Ceil is: "<<cl;
}