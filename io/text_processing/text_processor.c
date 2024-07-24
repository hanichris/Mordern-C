/**
 * @file: text_processor.c
 * @author: hanichris
 * 
 * Program that explores text processing in c.
 */
#include <stdio.h>
#include "text_processor.h"

/**
 * searchs for the substring `subs` in the string `s`.
 * 
 * @param[in] s the string to search in.
 * @param[in] subs the word to look for in the string.
 * @return returns the first character of the substring in the string. Otherwise, 0
 * if the substring is not found or if either string or substring is null.
 */
char* find_word(char const* s, char const* subs) {
    char* ret = 0;
    if (s && subs) ret = strstr(s, subs);
    return ret;
}

/**
 * finds the substring `w` in the string `s` and replaces it with the new
 * word `r` if the substring was found. The caller of the function is
 * responsible for freeing the memory allocated for the character array
 * by calling free().
 * 
 * @param[in] size the length of the string.
 * @param[in] s the string to perform a find and replace.
 * @param[in] m the length of the substring `word`,
 * @param[in] word the substring to search for in the string.
 * @param[in] n the length of the substring `replace`.
 * @param[in] replace the word to replace the substring with if found.
 * @return returns a new string with the first occurrence of the substring
 * `word` replaced with the new substring `replace` or the whole string replaced
 * with the string `replace` if an empty string was passed as the search word. Otherwise,
 * 0 is returned if the word was not found in the string.
 */
char* replace_word(
    size_t size, char const s[size],
    size_t m, char const word[m],
    size_t n, char const replace[n]
) {
    char* ret = 0;
    size_t len = 0;
    if (memchr(s, 0, size + 1) && memchr(word, 0, m + 1) && memchr(replace, 0, n + 1)) {
        ret = malloc(sizeof(char[(size - m) + n + 1]));
        if (!ret) return 0;

        char* ptr = find_word(s, word);
        if (ptr) {
            if (!m) {
                ret = realloc(ret, sizeof(char[n + 1]));
                if (!ret) return 0;
            }
            char* temp = ret;
            size_t prev_size = ptr - s;
            len = prev_size + n;
            memcpy(temp, s, prev_size);
            temp += prev_size;
            memcpy(temp, replace, n);
            if (!m) goto RET;
            temp += n;
            memcpy(temp, s + prev_size + m , size - (m + prev_size));
            len += size - (m + prev_size);
        } else {
            free(ret);
            return 0;
        }
    }
    RET:
    ret[len] = '\0';
    return ret;
}