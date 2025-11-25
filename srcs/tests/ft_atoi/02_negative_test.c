#include "../../../includes/libunit.h"

int ft_atoi_negative_test(void)
{
    char str[] = "-123";
    int expected = -123;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
