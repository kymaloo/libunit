#include "../../../includes/libunit.h"

int basic_test(void)
{
    char str[] = "Hello, World!";
    size_t expected = 13;
    size_t result = ft_strlen(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}