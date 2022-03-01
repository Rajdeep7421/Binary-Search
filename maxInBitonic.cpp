/**
 * @file maxInBitonic.cpp
 * @author Rajdeep Chattaraj
 * @brief find maximum in bitonic array.
 *         given a bitonic array find the maximum value of the array.
 *         An  array is said to be bitonic if it has an increasing sequence of integers
 *         followed immediately by a decreasing sequence of integers.
 * @date 2022-03-01
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

int maxInBitonicArray(vector<int>input) {
    int n = input.size();
    int start = 0;
    int end = n - 1;

    while(start<=end) {
        int mid = start + ((end - start) >> 1);

        if(mid > 0 && mid < n - 1) {
            if(input[mid] > input[mid - 1] && input[mid] > input[mid + 1]) {
                return mid;
            }
            else if(input[mid - 1] < input[mid] && input[mid] < input[mid + 1] ) {
                start = mid + 1;
            }
            else if(input[mid - 1] > input[mid] && input[mid] > input[mid + 1]) {
                end = mid -1;
            }
        }
        if(mid == 0 || mid == n-1) {
            return -1;
        }

    }
    return -1;
}
int main() {
    
    vector<int>input = {23,34,56,78,67,45,24,11};
    vector<int>badInput = {78,67,45,24,11};
    int ans = maxInBitonicArray(innput);
    cout<<ans<<endl;
    return 0;
}