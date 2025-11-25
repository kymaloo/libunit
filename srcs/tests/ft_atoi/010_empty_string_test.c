#include "../../../includes/libunit.h"

int ft_atoi_empty_string_test(void)
{
    char str[] = "";
    int expected = 0;
    int result = ft_atoi(str);

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
