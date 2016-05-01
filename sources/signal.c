/*
 * C function for the simplest low-pass filter
 *
 *	y(n) = x(n) + x(n-1)
 *
 */
double simplest_low_pass(double *x, double *y, int M, double xm1)
{
	int n;

	y[0] = x[0] + xm1;
	for (n = 1; n < M; n++)
		y[n] = x[n] + x[n-1];

	return x[M-1];
}

void main(void)
{
	double x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double y[10];

	int i;
	int N = 10;
	int M = N/2; /* block size */
	double xm1 = 0;

	xm1 = simplest_low_pass(x, y, M, xm1);
	xm1 = simplest_low_pass(&x[M], &y[M], M, xm1);

	for (i = 0; i < N; i++)
		fprintf(stdout, "x[%d] = %f\ty[%d] = %f\n", i, x[i], i, y[i]);

	exit(EXIT_SUCCESS);
}
