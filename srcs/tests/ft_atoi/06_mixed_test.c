#include "../../../includes/libunit.h"

int ft_atoi_mixed_test(void)
{
    char str[] = "  -456abc";
    int expected = -456;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
