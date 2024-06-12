#include<bits/stdc++.h>
using namespace std;

//Brute Force Method  <<--
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 && nums[i] > nums[i + 1]) {
            return i;
        } else if (i == n - 1 && nums[i] > nums[i - 1]) {
            return i;
        } else if (i > 0 && i < n - 1 && nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
            return i;
        }
    }
    return -1;    
}

// Binary Search Optimized Method <<--
int findPeakElement1(vector<int>& nums) {
    if(nums.size() == 1){
        return 0;
    }
    int low = 0;
    int high= nums.size() - 1;
    int n = nums.size();
    while(low <= high){
        int mid = low + (high - low)/2;         // To prevent Integer Overflow
        if(mid > 0 && mid < n - 1){
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid-1] > nums[mid]){
                high = mid - 1;
            }else{
                low  = mid + 1;
            }
        }else if(mid == 0){
            if(nums[0] > nums[1]){
                return 0;
            }else{
                return 1;
            }
        }else if(mid == n-1){
            if(nums[n-1] > nums[n-2]){
                return n-1;
            }else{
                return n-2;
            }
        }
    }
    return -1;
}
       
int main(){
    int n;  cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){ 
        cin >> nums[i];
    }
    cout << findPeakElement(nums) << endl;
    cout << findPeakElement1(nums)<< endl;
    return 0;
}