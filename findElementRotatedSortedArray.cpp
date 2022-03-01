/**
 * @file findElementRotatedSortedArray.cpp
 * @author Rajdeep Chattaraj
 * @brief suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *        you are given a target value to search. If found in the array returen its index,otherwise return -1.
 *        you may assume n duplicate exists in the array. time complexity O(logn);
 * 
 * @date 2022-03-01
 * @copyright Copyright (c) 2022
 * 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int binarySearch(vector<int>input,int K,int start,int end) {
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

int findPivot(vector<int>input) {
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
        else if(input[start] <= input[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int>input = {30, 40, 50, 60, 70, 10, 20}; // sorted array
    int pivot = findPivot(input);
    int K = 50;
    int n = input.size();
    
    int fromLeft = binarySearch(input,K,0,pivot - 1);
    if(fromLeft == -1) {
        int fromRight = binarySearch(input,K,pivot,n - 1);
        cout<<fromRight<<endl;
    }
    else {
        cout<<fromLeft<<endl;
    }
    return 0;
}