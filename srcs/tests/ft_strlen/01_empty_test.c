#include "../../../includes/libunit.h"

void empty_test(void)
{
    if (ft_strlen("") != 0)
        exit(EXIT_FAILURE);
        // return (-1);
    exit(EXIT_SUCCESS);
    // return (0);
}
