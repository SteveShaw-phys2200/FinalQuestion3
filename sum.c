/*
 * this program calculates a sum to accuracy of 3macheps.
 */
#define PI 3.14159265359
#include <stdio.h>

int main (void)
{
	float macheps = 1;
	float sum = 0; // running count of calculated sum
	float exact = PI*PI*PI*PI/90.; // the exact vaule of sum
	int n = 10; // number of terms in sum

	/* find macheps */
	while ((float)(1 + macheps) != 1)
	{
		macheps /= 2;
	}
	printf("macheps = %g\n", macheps);

	
	int nreps = 4;
	printf(" n	sum		exact	err	errmax\n");
	for (int i = 0; i < nreps; i++)
	{
		sum = 0; // reset
		n *= 2; // double number of terms

		/* reverse sum to add small terms to small sum */
		for (int k = n; k > 0; k--)
		{
			float w = 1. / k;
			sum += w*w*w*w;
		}

		float errmax = 3. * macheps;
		float err = exact - sum;
		printf("%3.1d  %1.8f  %1.8f  %1.8f  %1.8f\n", 
				n, sum, exact, err, errmax);
	}
	return 0;
}
