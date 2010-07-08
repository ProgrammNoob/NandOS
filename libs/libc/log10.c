#include <math.h>
#include <errno.h>
/**
 * Logoarithmus zur Basis 10 berechnen
 * @param x
 * @return
 */
double log10(double x)
{
    double one = 1;
    double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2t;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Logoarithmus zur Basis 10 berechnen
 * @param x
 * @return
 */
float log10f(float x)
{
    float one = 1;
    float res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2t;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

/**
 * Logoarithmus zur Basis 10 berechnen
 * @param x
 * @return
 */
long double log10l(long double x)
{
    long double one = 1;
    long double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2t;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

#ifdef __cplusplus
};
#endif