#include "../../../includes/libunit.h"

int ft_atoi_sign_test(void)
{
    char str[] = "+99";
    int expected = 99;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
