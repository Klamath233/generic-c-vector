/** A generic vector implementation in C
 *  Author: Xi Han <xihan94@ucla.edu>
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__
#define INIT_SIZE 4
#include <stddef.h>

typedef struct {
	void *array;
	size_t element_size;
	size_t length;
	size_t max_length;
} vector;

void vector_init(vector *vec, size_t size);
void vector_append(vector *vec, void *obj, size_t size);
size_t vector_length(vector *vec);
void vector_get_array(vector *vec, void **dest, size_t *length);
void vector_free(vector *vec);

#endif
