/**
 * @file floorOfAnElement.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

int floorOfAnElement(vector<int>input,int key) {
    int start = 0;
    int end = input.size() - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + ((end - start) >> 1);
        if(input[mid] == key) {
            return input[mid];
        }
        else if(input[mid] < key) {
            ans = mid;
            start = mid + 1; 
        }
        else {
            
            end = mid - 1;
        }
    }
    return input[ans];
}
int main()
{

    vector<int>arr = {1,2,3,4,8,10,10,12,19};
    int key = 10;

    int ans = floorOfAnElement(arr,key);
    cout<<ans;
    return 0;
}