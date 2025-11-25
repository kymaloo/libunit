#include "../../../includes/libunit.h"

int ft_atoi_leading_zeros_test(void)
{
    char str[] = "00042";
    int expected = 42;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
