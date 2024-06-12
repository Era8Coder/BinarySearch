#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Firstly we will see which is the best Row to have the traversal
    int low = 0;
    int high= matrix.size();
    // cout << "s";
    while(low <= high){
        int mid = (low + high)/2;
        if(matrix[mid][0] == target){               // Traversing on the first COLUMN Till where we have to move
            return true;
        }else if(matrix[mid][0] > target){
            high = mid - 1;
            // cout << "n";
        }else{
            low  = mid + 1; 
        }
    }
    
    int row = high;
    if(row < 0 || row >= matrix.size()){
        return false;
    }
    // cout << "e";
    int low_new = 0;                             // New Low
    int high_new = matrix[row].size() - 1;

    while(low_new <= high_new){
        int mid = (low_new + high_new)/2;
        if(matrix[row][mid] == target){
            return true;
        }else if(matrix[row][mid] > target){
            high_new = mid - 1;
        }else if(matrix[row][mid] < target){
            // cout << "h";
            low_new  = mid + 1;
            // cout << "a";
        }
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};               // Creating a 2D Array
    int target; cin >> target;
    // Make Target 5 -->> <3
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}