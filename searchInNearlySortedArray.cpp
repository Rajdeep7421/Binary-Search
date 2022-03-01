/**
 * @file searchInNearlySortedArray.cpp
 * @author Rajdeep Chattaraj
 * @brief search in nearly sorted array 
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * Nearly Sorted Array : an element arr[i] can be swapped with either arr[i+1] or arr[i-1] 
 */

#include<iostream>
#include<vector>
using namespace std;

int searchNearlySortedArray(vector<int>arr,int key) {

    int start = 0;
    int end = arr.size() - 1;
    while(start<=end) {
        int mid = start + ((end - start) >> 1);

        if(arr[mid] == key) {
            return mid;
        }
        if(mid < arr.size() - 1 && arr[mid + 1] == key) {
            return mid + 1;
        }

        if(mid > 0 && arr[mid - 1] == key) {
            return mid - 1;
        }

        else if(arr[mid] > key) {
            end = mid - 2;
        }
        else {
            start = mid + 2;
        }
    }
    return -1;
}
int main()
{

    vector<int>arr = {10, 3, 40, 20, 50, 50, 50, 80, 70};
    int key = 70;
    int ans = searchNearlySortedArray(arr,key);
    cout<<ans<<endl;
    
    return 0;
}