#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"
#include "vector.h"
#include "string.h"

static void vector_resize(vector *vec);

void
vector_init(vector *vec, size_t size)
{
	vec->array = checked_malloc(INIT_SIZE * size);
	vec->element_size = size;
	vec->length = 0;
	vec->max_length = INIT_SIZE;
	vector_resize(vec);
}

void
vector_append(vector *vec, void *obj, size_t size)
{
	if (size != vec->element_size) {
		fprintf(stderr, "Error: vector_append: unmatched type size.\n");
		exit(1);
	}
	memcpy(vec->array + vec->length * vec->element_size, obj, size);
	vec->length++;
	vector_resize(vec);
}

size_t
vector_length(vector *vec)
{
	return vec->length;
}

void
vector_get_array(vector *vec, void **dest, size_t *length)
{
	// The copied array is guarateed to be terminated with a zero.
	memset(vec->array + vec->length * vec->element_size, 0, vec->element_size);
	*dest = checked_malloc(vec->length * vec->element_size);
	memcpy(*dest, vec->array, vec->length * vec->element_size);
	*length = vec->length;
}

void
vector_free(vector *vec)
{
	free(vec->array);
}

static void
vector_resize(vector* vec)
{
	if (vec->length == vec->max_length) {
		vec->array = checked_realloc(vec->array, vec->max_length *
		                                         vec->element_size *2);
		vec->max_length *= 2;
	}
}
