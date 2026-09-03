#include <stdbool.h>
#include <stdio.h>

#include "sum_arr.h"

#define ARR_LEN 2

int main(void) 
{
    int arr[ARR_LEN] = {5, 5};
    int truth = sum_array(arr, ARR_LEN);
    float average = avg(truth, ARR_LEN);
    printf("Sum of array is: %d\n", truth);
    printf("average of array: %.3f", average);
    return 0;
}


// Returns sum of integer array elements
int sum_array(int *arr, int arr_len) 
{
    int cnt = 0;
    if(arr != NULL) 
    {
    int sum = 0;
    while (cnt < arr_len)
    {
        sum += *arr;
        cnt += 1;
        arr++;
    }
    return sum;
    } 
    else 
    {
        return -1;
    }
}

// Calculate avg = y / x = sum / sample_count
float avg(float y, float x) 
{
    if (x != 0) 
    {
        float average = (y / x);
        return average;
    }
}