#include "../../../includes/libunit.h"

int ft_strlen_empty_test(void)
{
    if (ft_strlen("") != 0)
        return (LU_KO);
    return (LU_OK);
}
