#include <stdio.h>

#define SAMPLE double

/* initialize the filter */
/**
 * \fn		void clear_fir(int n_taps, SAMPLE z[])
 * \brief	Initialize the filter by inserting zeros in the delay line
 *
 * \param[in]	n_taps		number of taps in the filter
 * \param[in]	z		FIR delay line array
 */
void clear_fir(int n_taps, SAMPLE z[])
{
	int ii;

	for (ii = 0; ii < n_taps; ii++)
		z[ii] = 0;
}


/**
 * \fn		SAMPLE fir_basic(SAMPLE input, int n_taps, const SAMPLE h[], SAMPLE z[])
 * \brief	Create a simple basic FIR filter
 *
 * \param[in]	input		input sample data
 * \param[in]	n_taps		number of taps in the filter
 * \param[in]	h		FIR coefficient array
 * \param[in]	z		FIR delay line array
 *
 * \return	the MAC accumulator
 */
SAMPLE fir_basic(SAMPLE input, int n_taps, const SAMPLE h[], SAMPLE z[])
{
	int ii;
	SAMPLE accum;

	/* Store the input in the delay line */
	z[0] = input;

	/* Compute the FIR filter */
	accum = 0;

	for (ii = 0; ii < n_taps; ii++)
		accum += h[ii] * z[ii];

	/* shift the delay line */
	for (ii = n_taps - 2; ii >= 0; ii--)
		z[ii + 1] = z[ii];

	return accum;
}
