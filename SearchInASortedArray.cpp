#include<bits/stdc++.h>
using namespace std;

int bin_srch(vector<int> &v, int low, int high, int tgt){
    if(v.size() == 0){
        return -1;
    }
    
    while(low <= high){
        int mid = low + (high - low)/2;         // To prevent Integer OverFlow
        if(v[mid] == tgt){
            return mid;
        }else if(v[mid] > tgt){
            high = mid - 1;
        }else{
            low  = mid + 1;
        }
    }

    return -1;          // If not Found then return "-1"
}

int minimum_index(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int high= n - 1;

    if(arr[low] <= arr[high]){
        return 0;
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        int prev = (mid + n - 1)%n;
        int next = (mid + 1)%n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
            return mid;
        }else if(arr[mid] <= arr[high]){
            high = mid - 1;
        }else if(arr[mid] >= arr[0]){
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    int n;  cin>>n;
    int tgt;    cin>>tgt;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int mini = minimum_index(v);
    if(mini == 0){
        cout << bin_srch(v, 0, v.size()-1, tgt) << endl;
    }else{
        int low1 = 0;
        int high1= mini - 1;
        int low2 = mini;
        int high2= v.size()-1;
        int m = bin_srch(v, low1, high1, tgt);
        int n = bin_srch(v, low2, high2, tgt);
        if(m!=-1){
            cout << m << endl;
        }else if(n!=-1){
            cout << n << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}