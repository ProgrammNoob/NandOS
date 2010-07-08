#include <math.h>
#include <errno.h>
/**
 * Quadratwurzel berechnen.
 * @param x
 * @return
 */
double sqrt(double x)
{
    double res;
    /*if (x <  0.0) {
        errno = EDOM;
        return NAN;
    }*/
    asm("fsqrt" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Quadratwurzel berechnen.
 * @param x
 * @return
 */
float sqrtf(float x)
{
    float res;
    /*if (x < 0.0) {
        errno = EDOM;
        return NAN;
    }*/
    asm("fsqrt" : "=t" (res) : "0" (x));
    return res;
}

/**
 * Quadratwurzel berechnen.
 * @param x
 * @return
 */
long double sqrtl(long double x)
{
    long double res;
    /*if (x < 0.0) {
        errno = EDOM;
        return NAN;
    }*/
    asm("fsqrt" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
};
#endif