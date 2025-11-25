#include "../../../includes/libunit.h"

int ft_atoi_zero_test(void)
{
    char str[] = "0";
    int expected = 0;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
