#include <stdio.h>
#include <stdbool.h>

#include "count_letters.h"

int main(void) 
{
    char *string = "JOU";
    int letter_count = 0;
    int *pcount = &letter_count;
    printf("WELCOME\n");
    bool counted = count_letters(string, pcount);
    printf("Success? => %d\n", counted);
    if (counted == false) 
    {
        printf("A pointer was null\nTry\nAgain\n");
    }
    else 
    {
    printf("Here's the letter count: %d\n", letter_count);
    printf("The string is: %s", string);
    }
    return 0;
}

// Counts the letters in the string *str
// Returns false if *str is NULL
// Returns true if succesfully counted the letters;
// Doesn't remove whitespaces...
bool count_letters(const char *str, int *ltr_cnt) 
{
    if (str != NULL && ltr_cnt != NULL) 
    {    
    const char *start = str;
    // Initializing the end of the string
    while (*start != '\0') 
    {
        start++;
        *ltr_cnt += 1;    
    }
    if (*start == '\0') 
    {
        return true;
        // END OF STRING
    }
    }
    else 
    {
        return false;
    }
}