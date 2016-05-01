/**
 * @file	tools.h
 * @brief	header file for the different tools used here and there
 */
#ifndef _tools_h
#define _tools_h
#define DEBUG() \
	fprintf(stderr, "\nDEBUG\n%s:%s:%d\n\n", __FILE__, __func__, __LINE__)

unsigned int ModuloInc(const unsigned int value, const unsigned int modulus);
#endif /* _tools_h */
