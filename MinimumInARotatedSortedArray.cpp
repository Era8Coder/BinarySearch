#include<bits/stdc++.h>
using namespace std;

int min_idx(vector<int> &v){
    int n = v.size();
    int low = 0;
    int high= n-1;

    if(v[low] <= v[high]){
        return 0;                   // Then array is already sorted on itself :)
    }

    while (low <= high )
    {
        int mid = low + (high - low)/2;         // {High - Low} => To Prevent Integer Flow <<--
        int prev= (mid + n - 1)%n;
        int next= (mid + 1)%n;
        
        if(v[mid] <= v[prev] && v[mid] <= v[next]){
            return mid;
        }else if(v[mid] <= v[high]){
            high = mid - 1;
        }else if(v[mid] >= v[0]){
            low  = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }   
    // cout << min_idx(v) << endl;
    cout << v[min_idx(v)] << endl;
    return 0;
}