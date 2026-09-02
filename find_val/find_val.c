#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "find_val.h"

#define ARR_LEN 5

int main(void)
{
    int array[ARR_LEN] = {5, 10, 15, 22, 223};
    int min_val, max_val;

    find_min_max(array, ARR_LEN, &min_val, &max_val);
    printf("Min: %d Max: %d\n", min_val, max_val);    

    return 0;
}

// Function that finds the min and max values from an array
// Returns false if array length is 0, or the pointers are NULL
// Returns true if min/max were succesfully found
bool find_min_max(const int *arr, const int arr_len, int *pmin, int *pmax) 
{
    bool searching = true;
    const int *left, *right;
    int cur_min, cur_max;
    // Checking if pointers are NULL
    if (arr_len <= 0 || pmin == NULL || pmax == NULL) 
    {
        return false;
    }
    else 
    {
        cur_min = *arr;
        cur_max = *arr;
        left = arr; // Initializing two pointers one in the left, one in the right of the array.
        right = arr + (arr_len - 1);   
        while(left <= right) 
        {
            // Left pointer checks
            if (*left < cur_min) 
            {
                cur_min = *left;
            }
            if (*left > cur_max) 
            {
                cur_max = *left;
            }
            // Right pointer checks
            if (*right < cur_min) 
            {
                cur_min = *right;
            }
            if (*right > cur_max) 
            {
                cur_max = *right;
            }
        left++;
        right--;
        } 
    }
    *pmin = cur_min;
    *pmax = cur_max;
    return true; //Succesfully found min/max    
}