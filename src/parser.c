#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "yajl/yajl_tree.h"
#include "tools.h"

#define DEFAULT_CONFIG_FILE "/.ewo.json"


static unsigned char file_data[65536];

void PrintValue(
	yajl_val node,
	char main_node[],
	char key[],
	const char *value_type)
{
	/* Build the structure necessary to perform the search in the SAX */
	const char *path[] = { main_node, key, (const char *) 0 };

	if (value_type == "string") {
		yajl_val v = yajl_tree_get(node, path, yajl_t_string);

		if (v)
			fprintf(stdout, "%s/%s: %s\n", path[0], path[1], YAJL_GET_STRING(v));
		else
			fprintf(stderr, "No such node: %s/%s\ncheck the type", path[0], path[1]);
	} else if (value_type == "number") {
		yajl_val v = yajl_tree_get(node, path, yajl_t_number);
		if (v)
			fprintf(stdout, "%s/%s: %s\n", path[0], path[1], YAJL_GET_NUMBER(v));
		else
			fprintf(stderr, "No such node: %s/%s\ncheck the type", path[0], path[1]);
	}
}

/**
 * \fn		const char *GetStringParam(yajl_val json_obj, char node[], char[])
 * \brief	Return the value of a string parameter in a configuration file.
 *
 * \param[in]	json_obj	Object containing the JSON content.
 * \param[in]	node		Node where is store the targeted value.
 * \param[in]	key		Key corresponded to the targeted value.
 *
 * \return	Return the string value if success or NULL.
 */
const char *GetStringParam(yajl_val json_obj, char node[], char key[])
{
	const char *path[] = { node, key, (const char *) 0 };
	yajl_val value = yajl_tree_get(json_obj, path, yajl_t_string);
	const char *str_value = NULL;

	if (value) {
		str_value = YAJL_GET_STRING(value);
	} else {
		fprintf(stderr, "No such node: %s/%s\ncheck your node or type of node",
			path[0], path[1]);
		str_value = NULL;
	}

	return str_value;
}

/**
 * \fn		int GetIntegerParam(yajl_val json_obj, char node[], char key[]
 * \brief	Return the value of an integer parameter in a configuration file.
 *
 * \param[in]	json_obj	Object containing the JSON content.
 * \param[in]	node		Node where is store the targeted value.
 * \param[in]	key		Key corresponded to the targeted value.
 *
 * \return	Return the integer value if success or -1.
 */
int GetIntegerParam(yajl_val json_obj, char node[], char key[])
{
	const char *path[] = { node, key, (const char *) 0 };
	yajl_val value = yajl_tree_get(json_obj, path, yajl_t_number);
	int int_value = -1;

	if (value) {
		int_value = YAJL_GET_INTEGER(value);
	} else {
		fprintf(stderr, "No such node: %s/%s\ncheck your node or type of node",
			path[0], path[1]);
		int_value = -1;
	}

	return int_value;
}

/**
 * \fn		int FreeConfigFile(yajl_val node)
 * \brief	Deallocate the memory containing the JSON config file
 *
 * Here an example on how you can use it:
 * PrintValue(node, "deviceSetup", "sample_format", "string");
 * PrintValue(node, "deviceSetup", "samplerate", "number");
 *
 * \param[in]	node	node containing the JSON dump
 *
 * \return	return EXIT_SUCCESS if the memory is correctly deallocated.
 *
 * \todo Find a way to ensure that the node has been correctly
 * deallocate before returning EXIT_SUCCESS.
 */
int FreeConfigFile(yajl_val node)
{
	yajl_tree_free(node);
	return EXIT_SUCCESS;
}


/**
 * \fn		int LoadConfigFile(void)
 * \brief	Load the JSON configuration file
 *
 * Don't forget to call the FreeConfigFile() after having used the
 * configuration file.
 *
 * \return	return EXIT_SUCCESS if the configuration file is loaded
 *		correctly.
 * \todo Give the possibilty to load another configuration file using commande
 * line or GUI. If nothing is given then load the default one or last saved.
 * work as well on the return value to ensure that the proper code is returned
 * to the program.
 */
yajl_val LoadConfigFile(void)
{
	FILE *fp = NULL;
	size_t rd;
	yajl_val node;
	char err_buffer[1024];
	int error;
	const char *home_dir;
	char config_file[512];

	/* Concatenation of the $HOME folder with the file name */
	home_dir = GetHomeDir();
	strcpy(config_file, home_dir);
	strcat(config_file, DEFAULT_CONFIG_FILE);

	file_data[0] = err_buffer[0];

	error = IsFileExist(config_file);
	if (error > 0) {
		/* Raise an error if false */
		fprintf(stderr, "Error %d: %s\n", error, strerror(error));
		exit(error);
	}

	fp = fopen(config_file, "r");
	/* read the entire config file */
	rd = fread((void *) file_data, 1, sizeof(file_data) - 1, fp);


	/* file error handling */
	if (rd == 0 && !feof(stdin)) {
		fprintf(stderr, "Error encountered on file read\n");
		exit(EXIT_FAILURE);
	} else if (rd >= sizeof(file_data) - 1) {
		fprintf(stderr, "Config file too big\n");
		exit(EXIT_FAILURE);
	}

	/* parse  the config file */
	node = yajl_tree_parse(
			(const char *) file_data,
			err_buffer,
			sizeof(err_buffer));

	/* parse error handling */
	if (node == NULL) {
		fprintf(stderr, "Parse error: ");
		if (strlen(err_buffer))
			fprintf(stderr, "%s", err_buffer);
		else
			fprintf(stderr, "Unknown error");

		fprintf(stderr, "\n");
		exit(EXIT_FAILURE);
	}


	/*
	 * Keep an example to reuse later on.
	 */
	/*
	const char * test = GetStringParam(node, "deviceSetup", "sample_format");
	int test2 = GetIntegerParam(node, "deviceSetup", "samplerate");
	fprintf(stdout, "my value is: %s\n", test);
	fprintf(stdout, "my value is: %d\n", test2);
	FreeConfigFile(node);
	*/
	return node;
}


/*
GetParam(param_name) {}
SetParam() {}
SaveConfigFile() {}
*/
