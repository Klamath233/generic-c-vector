#include <stdio.h>
#include "vector.h"

int main()
{
	vector v;
	vector_init(&v, sizeof(char));
	char c = 'h';
	vector_append(&v, &c, 1);
	c = 'e';
	vector_append(&v, &c, 1);
	c = 'l';
	vector_append(&v, &c, 1);
	c = 'l';
	vector_append(&v, &c, 1);
	c = 'o';
	vector_append(&v, &c, 1);
	c = '\n';
	vector_append(&v, &c, 1);
	size_t str_len = 0;
	char *s;
	vector_get_array(&v, (void **)&s, &str_len);
	vector_free(&v);
	printf("%s", s);
	return 0;
}
