#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_NAME_SZ 256
int main()
{
    printf("MAIN_2\n");
    char user_input[MAX_NAME_SZ];
    printf("Enter a string: ");
    fgets(user_input, MAX_NAME_SZ, stdin);
    int length = strlen(user_input);

    if(user_input[length-1] == '\n')
    {
        user_input[length-1] = '\0';
    }

    for (int i = 0; i < length; i++)
    {
        if (isalpha(user_input[i]))
        {
            user_input[i] = tolower(user_input[i]);
        }
        else if (isdigit(user_input[i]))
        {
            continue;
        }
        else
        {
            for (int j = i; j < length; j++)
            {
                user_input[j] = user_input[j + 1];
            }
            length--;
            i--;
        }
    }
    bool isPalindrome = true;
    char* start = user_input;
    char* end = user_input + length - 1;

    while(start < end)
    {
        if(*start != *end)
        {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome)
    {
        printf("%s is a Palindrome\n", user_input);
    }
    else
    {
        printf("%s is not a palindrome\n", user_input);
    }

    return 0;
}