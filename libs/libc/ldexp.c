
/**
 * Flieﬂkommazahl multiplitzieren.
 * @param x
 * @param exp
 * @return
 */
double ldexp(double x, int exp)
{
	double res;
	double e = exp;
	asm("fscale;"
	"fst %%st(0)" : "=t" (res) : "0" (x), "u" (e));
	return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Flieﬂkommazahl multiplitzieren.
 * @param x
 * @param exp
 * @return
 */
float ldexpf(float x, int exp)
{
	float res;
	float e = exp;
	asm("fscale;"
	"fst %%st(0)" : "=t" (res) : "0" (x), "u" (e));
	return res;
}

/**
 * Flieﬂkommazahl multiplitzieren.
 * @param x
 * @param exp
 * @return
 */
long double ldexpl(long double x, int exp)
{
	long double res;
	long double e = exp;
	asm("fscale;"
	"fst %%st(0)" : "=t" (res) : "0" (x), "u" (e));
	return res;
}

#ifdef __cplusplus
};
#endif