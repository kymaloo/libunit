#include "../../../includes/libunit.h"

int ft_atoi_basic_test(void)
{
    char str[] = "42";
    int expected = 42;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
