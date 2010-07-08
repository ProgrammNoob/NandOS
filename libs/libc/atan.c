#include <math.h>
/**
 * Arkustangens berechnen.
 * @param x
 * @return
 */
double atan(double x)
{
    double res;
    asm("fld1; fpatan" : "=t" (res) : "0" (x));
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
float atanf(float x)
{
    float res;
    asm("fld1; fpatan" : "=t" (res) : "0" (x));
    return res;
}

/**
 * Arkustangens berechnen.
 * @param x
 * @return
 */
long double atanl(long double x)
{
    long double res;
    asm("fld1; fpatan" : "=t" (res) : "0" (x));
    return res;
}


#ifdef __cplusplus
};
#endif