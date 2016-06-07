/**
 * @file		tools.c
 * @brief		Small function tools used here and there
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/**
 * @fn		unsigned int ModuloInc(const unsigned int value, const unsigned int modulus)
 * @brief	Modulo computation for buffer size.
 *
 * @param[in]	value		input value of the buffer
 * @param[in]	modulus		value of the modulus used
 *
 * @return	return the value of the modulus
 */
unsigned int ModuloInc(const unsigned int value, const unsigned int modulus)
{
	unsigned int my_value = value + 1;

	if (my_value >= modulus)
		my_value = 0;

	return my_value;
}

/**
 * \fn		void IsFileExist(const char *path)
 * \brief	Test the access to a given file.
 *
 * \param[in]	path	filename (include relative or absolute path to the given
 *			file to test.
 *
 * \return		Display an error message.
 *
 * \todo
 * It seems that exiting a program (using exit() function) outside the main
 * function can be dangerous regarding the memory deallocation and thread
 * issues. It would interesting to find the best practices on the matter. Second
 * thing to check is how to perform a proper unit test on a function using
 * exit().
*/
void IsFileExist(const char *path)
{
	int result;
	result = access(path, F_OK);
	if (result == -1) {
		errno = ENOENT;
		fprintf(stderr, "%s: %s\n", path, strerror(errno));
		exit(EXIT_FAILURE);
	}
}


/**
 * \fn		void DebugCwd(void)
 * \brief	Return the current working directory for the specified file
 *
 * \return	return a string of stdout with current working directory
 */
void DebugCwd(void)
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout,
			"DEBUG: Current working dir: %s in file %s:%d\n",
			cwd, __FILE__, __LINE__);
}
