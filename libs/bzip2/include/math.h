#ifndef MATH_H
#define MATH_H

// double
double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double x, double y);
double ceil(double x);
double cos(double x);
	//double cosh(double x);
double exp(double x);
double fabs(double x);
double floor(double x);
	//double fmod(double x);
	//double frexp(double x);
double ldexp(double x, int exp);
double log(double x);
double log2(double x);
double log10(double x);
	//double modf(double x);
double pow(double x, double y);
double sin(double x);
	//double sinh(double x);
double sqrt(double x);
double tan(double x);
	//double tanh(double x);

#ifdef __cplusplus
extern "C" {
#endif

// float
float acosf(float x);
float asinf(float x);
float atanf(float x);
float atan2f(float x, float y);
float ceilf(float x);
float cosf(float x);
	//float coshf(float x);
float expf(float x);
float fabsf(float x);
float floorf(float x);
	//float fmodf(float x);
	//float frexpf(float x);
float ldexpf(float x, int exp);	
float logf(float x);
float log2f(float x);
float log10f(float x);
	//float modff(float x);
float powf(float x, float y);
float sinf(float x);
	//float sinhf(float x);
float sqrtf(float x);
float tanf(float x);
	//float tanhf(float x);
	
//long double
long double acosl(long double x);
long double asinl(long double x);
long double atanl(long double x);
long double atan2l(long double x, long double y);
long double ceill(long double x);
long double cosl(long double x);
	//long double coshl(long double x);
long double expl(long double x);
long double fabsl(long double x);
long double floorl(long double x);
	//long double fmodl(long double x);
	//long double frexpl(long double x);
long double ldexpl(long double x, int exp);
long double logl(long double x);
long double log2l(long double x);
long double log10l(long double x);
	//long double modfl(long double x);
long double powl(long double x, long double y);
long double sinl(long double x);
	//long double sinhl(long double x);
long double sqrtl(long double x);
long double tanl(long double x);
	//long double tanhl(long double x);

#ifdef __cplusplus
};
#endif

#endif