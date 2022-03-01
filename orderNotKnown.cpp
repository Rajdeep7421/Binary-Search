/**
 * @file orderNotKnow.cpp
 * @author Rajdeep Chattaraj 
 * @brief Though we know that the array is sorted we dont't know if it's sorted in ascending or descending order.
 * 
 * @date 2022-02-28
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>input,int K,bool ascending) {

    int start = 0;
    int end = input.size() - 1;
    
    if(input.size()>1) {
        if(input[0] < input[1]) {
            ascending = true;
        }
    }

    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(input[mid] == K) {
            return mid;
        }
        else if(input[mid] < K) {
            if(ascending) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        else {
            if(ascending) {
                end = mid - 1;
            }
            else {
                
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int>input = {3,6,7,12,19,41}; // sorted array
    vector<int>input_des = {78,34,23,12,8,-3};
    bool isAscneding = false;
    int ans = binarySearch(input,19,isAscneding);
    int ans_des = binarySearch(input_des,12,isAscneding);
    cout<<ans<<endl;
    cout<<ans_des<<endl;
    return 0;
}