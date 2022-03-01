
/**
 * @file binary_search.cpp
 * @author Rajdeep Chattaraj
 * @brief binary search on sorted array
 * @date 2022-02-28
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>input,int K) {
    int start = 0;
    int end = input.size() - 1;

    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(input[mid] == K) {
            return mid;
        }
        else if(input[mid] < K) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int>input = {3,6,7,12,19,41}; // sorted array
    int ans = binarySearch(input,18);
    cout<<ans<<endl;
    return 0;
}