#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

int memcmp(const void *srca,const void *srcb,size_t n);
char strcmp(const char *str1, const char *str2);
void* memset(void* buf, int c, int n);
void* memcpy(void* dest, const void* src, size_t n);


#endif
