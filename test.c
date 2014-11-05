/*
 * test.c
 *
 *  Created on: Nov 4, 2014
 *      Author: Samiam
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char ** handle_string(char *line) {

	//1. find out side of array
	int len = strlen(line);
	int i = 0;
	int was_white = 1;
	int size = 0;
	while (i < len) {
		//		if theres whitespace...
		if (line[i] == ' ') {
			was_white = 1;
			line[i] = '\0';
		} else {
			if (was_white) {
				printf("Hit the next string starting with char: %c\n", line[i]);
				size++;
				was_white = 0;
			}
		}
		i++;
	}

	//2. malloc an array of size size
	char** array = (char**) malloc(size * sizeof(char*)); /*array of pointers */
	i = 0; /* index into the line - position in line */
	int a_index = 0; /* array index - for pointers */
	was_white = 1;
	while (i < len) {
		//		if theres whitespace...
		if (line[i] == '\0') {
			printf("Found a null byte at this spot, %c", line[i]);
			was_white = 1;
		} else { //there is a char there
			//and the previous thing was a null byte
			if (was_white) {
				printf("Adding a ref to the next string starting with char: %c\n", line[i]);
				was_white = 0;
				array[a_index] = &line[i];
				a_index++;
			}
		}

		i++;
	}

	return array;
//	char** line_ref = array;
//	return line_ref;

}

int main(void) {
	char buffer[] = "mycommand     arg1   nextarg arg3 not-arg-5-but-4";
	char *buff = malloc(10 * sizeof(char));

	char **ptr = handle_string(buffer);
	printf(
			"Address of pointer to array: %p, Adress of array: %p, Address of (first elem) of line: %p\n",
			&ptr, ptr, *ptr);

	int i;

	for (i = 0; i < 5; i++){
		printf("String #%p: %s\n", ptr[i], ptr[i]);
	}

}

//
//void test() {
//	//	ref
//
//	char a = 'a';
//	//	right
//	char *a1 = &a;
//
//char b[2] = "ab"
////	wrong
//char *b1 = b
//
//}
//char ** bad_handle_string(char *line) {
//	//	char *ptr_array;
//	char **ref;
//	int ref_index = 0;
//
//	//1. parse the line for whitespace
//	char* line_ref = line;
//	int len = strlen(line);
//	int i = 0;
//
//	while (i < len) {
//		//		if theres whitespace...
//		if (line[i] == ' ') {
//			printf("Good job you found it\n");
//			//		create a pointer
//			char *ptr = (char *) malloc(sizeof(char*));
//
//			//		have it ref the right spot
//			ptr = &line[i];
//			printf(
//					"Address of this index: %d, value of the pointer to the index: %d",
//					&line[i], ptr);
//
//			//		link it to the ref
//			ref[ref_index] = (char **)malloc(size(char*));
//			ref[ref_index] = &ptr;
//		}
//		i++;
//
//	}
//}
