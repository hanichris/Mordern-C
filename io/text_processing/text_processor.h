/**
 * @file: text_processor.h
 * @author: hanichris
 */
#if !defined(TEXT_PROCESSOR_H)
#define TEXT_PROCESSOR_H

#include <string.h>
#include <stdlib.h>

char* find_word(char const* s, char const* w);
char* replace_word(size_t size, char const s[size], size_t m, char const word[m], size_t n, char const replace[n]);

#endif // TEXT_PROCESSOR_H
