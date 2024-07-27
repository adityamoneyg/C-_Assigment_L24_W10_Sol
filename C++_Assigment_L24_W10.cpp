#include<iostream>
using namespace std;
int lastOccurrence(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            if(mid == n-1 || arr[mid+1] != x) return mid;
            else low = mid + 1;
        }
        else if(arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 4;
    cout << lastOccurrence(arr, n, target) << endl;
}

//                                      2 Solution

#include<iostream>
#include<vector>
using namespace std;
int countOnes(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int count = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == 1){
            count += high - mid + 1;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return count;
}
int main(){
    vector<int> arr = {0,0,0,0,1,1,1,1};
    cout << countOnes(arr) << endl; 
}

//                                 3 Solution

#include<iostream>
#include<vector>
using namespace std;
int findMaxOnes(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxRow = 0;
    int maxOnes = 0;
    for(int i=0; i<rows; i++){
        int count = 0;
        for(int j=cols-1; j>=0; j--){
            if(matrix[i][j] == 1){
                count++;
            }else{
                break;
            }
        }
        if(count > maxOnes){
            maxOnes = count;
            maxRow = i;
        }
    }
    return maxRow;
}
int main(){
    vector<vector<int>> matrix = {{0,0,1},{0,1,1},{1,1,1}};
    cout << findMaxOnes(matrix) << endl;
}

//                                   4 Solution

#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int n : nums) {
            if (n <= mid)
                count++;
        }
        if (count <= mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums) << endl;
}

//                                      5 Solution

#include<iostream>
#include<vector>
using namespace std;
bool isPerfectSquare(int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long midSquare = (long long)mid * mid;
        if (midSquare == n)
            return true;
        else if (midSquare < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}    
int main() {
    int n;
    cin >> n;
    cout << isPerfectSquare(n) << endl;
}

//                                     6 Solution

#include<iostream>
using namespace std;
int arrangeCoins(int n) {
    int rows = 0;
    while (n > 0) {
        rows++;
        n -= rows;
    }
    return rows - 1;
}
int main(){
    int n;
    cin >> n;
    cout << arrangeCoins(n) << endl;
}
