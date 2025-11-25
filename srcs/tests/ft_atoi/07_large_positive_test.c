#include "../../../includes/libunit.h"

int ft_atoi_large_positive_test(void)
{
    char str[] = "2147483647";
    int expected = 2147483647;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
