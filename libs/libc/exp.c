#include <math.h>
/**
 * Exponentialfunktion berechnen.
 * @param x
 * @return
 */
double exp(double x)
{
    double res;
    asm(
        "fldl2e;"
        "fmulp;"
        "fld %%st(0);"
        "frndint;"
        "fld1;"
        "fscale;"
        "fxch %%st(2);"
        "fsubp %%st(1);"
        "f2xm1;"
        "fld1;"
        "faddp;"
        "fmulp" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Exponentialfunktion berechnen.
 * @param x
 * @return
 */
float expf(float x)
{
    float res;
    asm(
        "fldl2e;"
        "fmulp;"
        "fld %%st(0);"
        "frndint;"
        "fld1;"
        "fscale;"
        "fxch %%st(2);"
        "fsubp %%st(1);"
        "f2xm1;"
        "fld1;"
        "faddp;"
        "fmulp" : "=t" (res) : "0" (x));
    return res;
}

/**
 * Exponentialfunktion berechnen.
 * @param x
 * @return
 */
long double expl(long double x)
{
    long double res;
    asm(
        "fldl2e;"
        "fmulp;"
        "fld %%st(0);"
        "frndint;"
        "fld1;"
        "fscale;"
        "fxch %%st(2);"
        "fsubp %%st(1);"
        "f2xm1;"
        "fld1;"
        "faddp;"
        "fmulp" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
};
#endif