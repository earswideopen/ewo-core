/**
 * @file	parser.h
 * @brief	header file for parsing of the configuration file
 */
#ifndef PARSER_H
#define PARSER_H

#include "yajl/yajl_tree.h"

void PrintValue(yajl_val node, char main_node[], char key[], const char *value_type);
yajl_val LoadConfigFile(void);
const char *GetStringParam(yajl_val json_obj, char node[], char key[]);
int GetIntegerParam(yajl_val json_obj, char node[], char key[]);
int FreeConfigFile(yajl_val node);

#endif /* PARSER_H */
