#include <stdbool.h>
#include <stdio.h>
#include "filter_evens.h"

#define SRC_LEN 4
#define DEST_LEN 4

int main(void) 
{
    // Source array
    int array[SRC_LEN] = {2, 3, 4, 5};
    int dest_arr[DEST_LEN] = {};
    int even_count = 0;
    int *pcount = &even_count;
    filter_evens(array, SRC_LEN, dest_arr, pcount);
    printf("even count: %d", even_count);
    return 0;
}


// Filters even numbers from an array, and places them to destination array
// Returns false if a pointer is NULL or SRC_LEN = 0
// Else returns true
bool filter_evens(const int *src, int src_len, int *dest, int *count) 
{
    if (src_len <= 0 || src == NULL || dest == NULL || count == NULL) 
    {
        return false;
    }
    else 
    {
        const int *ptr = src;
        const int *end = src + src_len;
        while (ptr < end) 
        {
          printf("%d\n", *ptr);
          int number = *ptr;
          // Number is odd
          /* 
          Example:
          number = 4, 8 bit binary = 0000 0100
          number 1 in 8 bit binary = 0000 0001
          Comparison goes as follows:
          0000 0100 &
          0000 0001 
          => 
          0000 0000
          */
          if ((number & 1) == 0) 
          {
            *dest = number;
            dest++;
            *count += 1;
          }
          ptr++;
        }
        return true;
    }

}

// Switches x and y
// Returns true if switches
// Returns false if pointers == NULL
bool switch_nums(int *x, int *y) 
{
    if (x != NULL && y != NULL) 
    {
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
    return true;
    }
    else 
    {
        return false;
    }
}