/**
 * @file NoOfRotationInSortedArray.cpp
 * @author Rajdeep Chattaraj
 * @brief find the rotation count in rotated sorted array. 
 *        Consider an array of distinct numbers sorted in increasing order.
 *        The array has been rotated(clockwise) k number of times. 
 *        Given such an array, find the value of k.
 *        arr = {15, 18, 2, 3, 6, 12}
 *        Output : 2
 * @date 2022-02-28
 * @copyright Copyright (c) 2022
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int NoOfRotationInSortedArray(vector<int>input) {
    int start = 0;
    int end = input.size() - 1;
    int n = input.size();

    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        int prev = (mid + n -1) % n;
        int next = (mid + 1) % n;
        if(input[mid] <= input[prev] && input[mid] <= input[next]) {
            return mid;
        }
        else if(input[mid] <= input[end]) {
            end = mid - 1;
        }
        else if(input[start] >= input[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int>input = {3,6,7,12,19,41}; // sorted array
    reverse(input.begin(),input.end());
    int ans = NoOfRotationInSortedArray(input);
    cout<<ans<<endl;
    return 0;
}