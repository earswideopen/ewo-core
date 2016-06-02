#ifndef FILTERS_H
#define FILTERS_h

#include <stdio.h>
#define SAMPLE double

void clear_fir(int n_taps, SAMPLE z[]);
SAMPLE fir_basic(SAMPLE input, int n_taps, const SAMPLE h[], SAMPLE z[]);
#endif /* FILTERS_H */
