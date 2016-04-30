#ifndef USEFULTOOLS
#define USEFULTOOLS
#define DEBUG() \
	fprintf(stderr, "\nDEBUG\n%s:%s:%d\n\n", __FILE__, __func__, __LINE__);
#endif

unsigned int ModuloInc(const unsigned int value, const unsigned int modulus);
