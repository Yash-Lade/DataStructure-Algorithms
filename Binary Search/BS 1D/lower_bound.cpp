#include<iostream>
#include<vector>
using namespace std;

// lower bound- arr[ids]>=target
int lowerBound(vector<int> arr, int n, int target){
    int left=0, right=n-1;
    int ans=n;
    // while(left<=right){
    //     int mid=  left + (right - left) / 2;

    //     if(arr[mid]>=target) ans=mid;

    //     if(target==arr[mid]) return mid;
        
    //     else if(target>arr[mid]){
    //         if(arr[mid]>=target) ans=mid;
    //         left=mid+1;
    //     }
    //     else{
    //         if(arr[mid]>=target) ans=mid;
    //         right=mid-1;
    //     }
    // }

    while(left<=right){
        int mid= left+(right-left)/2;

        if(arr[mid]>=target){
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
    int lb= lowerBound(arr, n, no);
    cout<<"The lower bound for given array is: "<<lb;
}