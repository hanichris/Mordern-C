#include <stdio.h>
#include "text_processor.h"


int main(void) {
    char const* test = "14.2. Formatted input. Similar to the printf family of functions for formatted output, the C library has a series of functions for formatted input: fscanf for input from an arbitrary stream, scanf for stdin, and sscanf from a string. For example, the following would read a line of three double values from stdin:";
    char const* word = "sscanf";
    char const* replace = "";

    size_t word_len = strlen(word);
    size_t test_len = strlen(test);
    size_t replace_len = strlen(replace);

    // char* found = find_word(test, word);
    // if (found) {
    //     printf("%s\n", test);
    //     for (size_t i = 0; i < (found - test); i++)
    //     {
    //         fputc('-', stdout);
    //     }
        
    //     printf("^ %.*s\n", (int)word_len, found);
    // } else {
    //     printf("'%s' not found in '%s'\n", word, test);
    // }

    char* ret = replace_word(test_len, test, word_len, word, replace_len, replace);
    if (ret)
    {
        printf("\nOriginal: '%s'\nNew: '%s'\n", test, ret);

        word_len ? printf("\nReplacement word: '%s'\n", word)
                 : printf("\nReplacing the whole string with '%s'\n", replace);

        printf("Original string length: %zu\n\nNew string length: %zu\n", test_len, strlen(ret));
        free(ret);
    } else {
        printf("Could not replace the word '%s' in '%s'.\n", word, test);
    }
    

    return EXIT_SUCCESS;
}