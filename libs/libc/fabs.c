
/**
 * Ermittelt den Absolutwert.
 * @param x
 * @return
 */
double fabs(double x)
{
	double res;
	if (x < 0.0)
	{
		res = -x;
	}
	else
	{
		res = x;
	}
	return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Ermittelt den Absolutwert.
 * @param x
 * @return
 */
float fabsf(float x)
{
	float res;
	if (x < 0.0)
	{
		res = -x;
	}
	else
	{
		res = x;
	}
	return res;
	}

/**
 * Ermittelt den Absolutwert.
 * @param x
 * @return
 */
long double fabsl(long double x)
{
	long double res;
	if (x < 0.0)
	{
		res = -x;
	}
	else
	{
		res = x;
	}
	return res;
}

#ifdef __cplusplus
};
#endif