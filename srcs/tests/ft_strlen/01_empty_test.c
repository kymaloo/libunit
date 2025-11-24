#include "../../../includes/libunit.h"

int empty_test(void)
{
    if (ft_strlen("") != 0)
        return (-1);
    return (0);
}
