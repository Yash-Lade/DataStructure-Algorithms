#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return true;
            
            // duplicate check
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low ++;
                high--;
            }
            //left sorted
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else 
                low=mid+1;
            }
            // right sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else 
                high=mid-1;
            }
        }
    return false;
}

int main(){
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter rotated sorted array elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    bool ans = search(nums, target);

    if(ans)
        cout << "Target is present in array. " ;
    else
        cout << "Target not found in array.";

    return 0;
}