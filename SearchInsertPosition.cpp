#include<bits/stdc++.h>
using namespace std;

int srch_insert(vector<int> &v, int target){
    int low = 0;
    int high= v.size() - 1;
    int mid = (low + high)/2; 

    while(low <= high){
        if(v[mid] == target){
            return mid;
        }else if(v[mid] > target){
            high = mid - 1;
        }else{  
            low  = mid + 1;
        }
        mid = (low + high)/2;
    }

    return low;
}

int main(){
    vector<int> v = {1,3,5,7,9};
    cout << srch_insert(v, 2) << endl;
    return 0;
}