#ifndef SETJMP_H
#define SETJMP_H
#include <stdint.h>

typedef uintptr_t jmp_buf[9];

#ifdef __cplusplus
extern "C" {
#endif

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int value);

#ifdef __cplusplus
};
#endif

#endif