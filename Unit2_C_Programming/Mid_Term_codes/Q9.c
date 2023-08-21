/*
 ============================================================================
 Name        : Q9.c
 Author      : Loay Tamer
 Description : c function to reverse words in string
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void reverseWords(char* str)
{
    int length = strlen(str);
    int start = 0;
    int end = 0;

    // Reverse the entire string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    // Reverse individual words
    while (end < length) {
        if (str[end] != ' ') {
            start = end;
            while (str[end] != ' ' && str[end] != '\0') {
                end++;
            }

            // Reverse the word
            int wordStart = start;
            int wordEnd = end - 1;
            while (wordStart < wordEnd) {
                char temp = str[wordStart];
                str[wordStart] = str[wordEnd];
                str[wordEnd] = temp;
                wordStart++;
                wordEnd--;
            }
        }
        else {
            end++;
        }
    }
}

int main()
{
    char str[50];
    printf("Enter string: ");
    fflush(stdin);fflush(stdout);
    gets(str);
    reverseWords(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
