#include <stdio.h>
#include <stdbool.h>

#include "reverse_str.h"

//#define STR_LEN 8
#define STRING "saippuakauppias"

int main(void) 
{
    char str[] = STRING;
    char *p_string = str;
    bool palindrome = reverse_string(p_string);
    if (palindrome == 1) 
    {
        printf("The word is a palindrome\n");
        printf("Here's the palindrome: %s\n", str);
    }
    else 
    {
        printf("NAY\n");
        printf("Here's the reversed str: %s\n", str);
    }
    return 0;
}

// Function reverses string, and checks if the string is a palindrome
// Returns true if the word was a palindrome
// False if the pointer to string was null
bool reverse_string(char *str) 
{
    if (str != NULL) 
    {
        bool palindrome = true;
        char *left, *right;
        char temp = 0;
        left = str;
        right = str;
        // Searching the endpoint
        while (*right != '\0') 
        {
            right++;
        }
        if (*right == '\0') 
        {
            right--;
        }

        // Running the loop until left passes right:
        while(left < right)
        {
          //If one character differs the word is not a palindrome  
          if (*left != *right) 
          {
            palindrome = false;
          }
          temp = *left;
          *left = *right;
          *right = temp; 
          left++;
          right--;
        }
        if (palindrome == true) 
        {
            return true;
        }
        else 
        {
            return false;
        }    
    }
    else if (str == NULL) 
    {
        return false;
    }
}