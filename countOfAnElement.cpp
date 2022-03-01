/**
 * @file countOfAnElement.cpp
 * @author Rajdeep Chattaraj
 * @brief count of an element in an sorted array
 * @date 2022-02-28
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstLastOccurence(vector<int> input,int K,bool firstOccurence) {
    int start = 0;
    int end = input.size() - 1;
    int ans = -1;
    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(input[mid] < K) {
            start = mid + 1;
        }
        else if(input[mid] > K) {
            end = mid -1;
        }
        else {
            ans = mid;
            if(firstOccurence) {
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int>input = {1,3,5,5,5,5,67,123,123,123,123,123,125};
    
    int firstOccurence = firstLastOccurence(input,123,true);
    int LastOccurence = firstLastOccurence(input,123,false);
    
    int ans = LastOccurence - firstOccurence + 1;
    cout<<ans<<endl;
    return 0;
}