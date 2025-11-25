#include "../../../includes/libunit.h"

int ft_atoi_whitespace_test(void)
{
    char str[] = "  \t\n42";
    int expected = 42;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
