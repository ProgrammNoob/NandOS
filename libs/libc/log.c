#include <math.h>
#include <errno.h>
/**
 * Natürlichen Logarithmus berechnen.
 * @param x
 * @return
 */
double log(double x)
{
    double one = 1;
    double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2e;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Natürlichen Logarithmus berechnen.
 * @param x
 * @return
 */
float logf(float x)
{
    float one = 1;
    float res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2e;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;
}

/**
 * Natürlichen Logarithmus berechnen.
 * @param x
 * @return
 */
long double logl(long double x)
{
    long double one = 1;
    long double res;
    /*if (x <= 0.0)
	{
        errno = EDOM;
        return NAN;
    }*/
    asm("fyl2x;"
        "fldl2e;"
        "fdivrp" : "=t" (res) : "0" (x), "u" (one));
    return res;

}

#ifdef __cplusplus
};
#endif