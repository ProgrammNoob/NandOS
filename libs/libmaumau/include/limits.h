#ifndef LIMITS_H
#define LIMITS_H

#define NAME_MAX 255

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

#define UCHAR_MAX 255

#define CHAR_MAX SCHAR_MAX
#define CHAR_MIN SCHAR_MIN

#define CHAR_BIT 8

#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

#define USHRT_MAX 65535

#define LONG_MAX 0x7FFFFFFF
#define LONG_MIN ((signed long) -0x80000000)

#define INT_MAX 0x7FFFFFFF
#define INT_MIN ((signed int) -0x80000000)

#define ULONG_MAX 0xFFFFFFFF
#define UINT_MAX 0xFFFFFFFF

#define _POSIX_PATH_MAX 4096
#define PATH_MAX _POSIX_PATH_MAX

#endif