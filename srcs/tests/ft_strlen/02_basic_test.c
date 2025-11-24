#include "../../../includes/libunit.h"
#include <string.h>

void basic_test(void)
{
    char *str2;
    char str[] = "Hello, World!";
    size_t expected = 13;
    size_t result = ft_strlen(str);

    str2 = NULL;
    *str2 = 'H';
    if (result != expected)
        exit(EXIT_FAILURE);
        // return (LU_KO);
    // return (LU_OK);
    exit(EXIT_SUCCESS);
}