/**
 * @file findposInfinite.cpp
 * @author Rajdeep Chattaraj
 * @brief find element in an infinite array(length is unknown)
 * @date 2022-03-01
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

int findPos(vector<int>arr,int target)
{
    int start = 0;
    int end = 1;
    int x = arr[0];

    while(x < target)  
    {
        start = end;
        end = end*2;
        x = arr[start];
    }

    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid]>target){
            end = mid - 1;
        }
        else if(arr[mid]<target){ 
            start = mid + 1;
        }
        else return mid;
    }
    return -1;

}
int main()
{
    vector<int>arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = findPos(arr, 10);
    cout<<ans;
    return 0;
}