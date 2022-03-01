/**
 * @file firstAndLastOccurence.cpp
 * @author Rajdeep Chattaraj 
 * @brief Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of ans element x in the given array.
 *          arr = {1,3,5,5,5,5,67,123,125}
 *          x = 5;
 *          Output : FO = 2
 *                  L0 5
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
    
    int ans = firstLastOccurence(input,123,true);
    int ans_last = firstLastOccurence(input,123,false);
    cout<<ans<<" "<<ans_last<<endl;
    return 0;
}