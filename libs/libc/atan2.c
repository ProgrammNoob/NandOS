#include <math.h>
/**
 * Arkustangens berechnen.
 * @param x
 * @return
 */
double atan2(double x, double y)
{
    double res;
    asm("fpatan" : "=t" (res) : "0" (y), "u" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Arkustangens berechnen.
 * @param x
 * @return
 */
float atan2f(float x, float y)
{
    float res;
    asm("fpatan" : "=t" (res) : "0" (y), "u" (x));
    return res;
}

/**
 * Arkustangens berechnen.
 * @param x
 * @return
 */
long double atan2l(long double x, long double y)
{
    long double res;
    asm("fpatan" : "=t" (res) : "0" (y), "u" (x));
    return res;
}

#ifdef __cplusplus
};
#endif