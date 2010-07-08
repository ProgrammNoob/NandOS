#include <math.h>
#include <errno.h>
/**
 * Logarithmus zur Basis 2 berechnen
 * @param x
 * @return
 */
double log2(double x)
{
    double one = 1;
    double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Logarithmus zur Basis 2 berechnen
 * @param x
 * @return
 */
float log2f(float x)
{
    float one = 1;
    float res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

/**
 * Logarithmus zur Basis 2 berechnen
 * @param x
 * @return
 */
long double log2l(long double x)
{
    long double one = 1;
    long double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

#ifdef __cplusplus
};
#endif