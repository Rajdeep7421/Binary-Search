/**
 * @file rotated_sorted_array.cpp
 * @author Rajdeep Chattaraj
 * @brief rotated sorted array
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;


// rotated sorted array
/*
different example:
                            rotation
    10 20 30 40 50 60 70       0 
    70 10 20 30 40 50 60       1
    60 70 10 20 30 40 50       2
    50 60 70 10 20 30 40       3
    40 50 60 70 10 20 30       4
    30 40 50 60 70 10 20       5
    20 30 40 50 60 70 10       6
    10 20 30 40 50 60 70       7
    10 20 30 40 50 60 70       14

no of rotation % no of element in array = 0

500 % 7 = 3

    after 500 rotation what will be the output?
    -> 500 % 7 = 3
     so I have to do 3 rotation to get the output after 500 rotation


*/

// find smaller element of rotated sorted array
/*
arr[] 

    60   70  10  20  30  40  50                  10  20  30   40 50  60  70

   st    b   s   m           e                   s                        b
   st    m       e

   60   70  10  20
   st    m  st   e

   10  20
i =2   3
   st   e
   m




*/


// 40 50 60 70 10 20 30


/*
no of element = 7
start = 0
end = n-1

mid = (start + end) /2;
mid = start + (end - start)/2; 
here, mid = 7/2 = 3

if(arr[mid]<arr[end]){
    end = mid;
}
else if(arr[mid]>arr[end]){
    start = mid + 1;
}

after one iteration:
start = 0
end = 3

mid = 1;

after two iterations:
start = 2
end = 3

mid = (3+2)/2 = 5/2 = 2;


*/

int smallest_element(int arr[],int n){
    int start = 0;
    int end = n-1;

    while(start < end){ 
        int mid = start + (end - start)/2;

        if(arr[mid]>arr[end]){
            start = mid + 1;
        }
        else if(arr[mid]<arr[end]){
            end = mid;
        }
    }
    return start;  // or end  because  at this moment start == end
}

int biggest_element(int arr[],int n){

    int smallest = smallest_element(arr,n);
    int biggest;
    if(smallest == 0){
        biggest = n-1;
    }
    else{
        biggest = smallest - 1;
    }
    return biggest;
}


int main()
{
    int arr[7] = {30, 40, 50, 60, 70, 10, 20};

    int smallest = smallest_element(arr,7);
    cout<<arr[smallest]<<endl;
    // smallest can give you no of rotation
    // if smallest = 5 then no of rotation = 5;
    int biggest = biggest_element(arr,7);
    cout<<arr[biggest]<<endl;

    return 0;
}