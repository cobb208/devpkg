#include <stdlib.h>
#include "dbg.h"

void *concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1);

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;

error:
    if(result)
        free(result);
    return NULL;
}