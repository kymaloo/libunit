#include "../../../includes/libunit.h"

int ft_strlen_launcher(void)
{
    t_test *tests = NULL;

    load_test(&tests, "Basic test", &ft_strlen_basic_test);
    load_test(&tests, "Empty test", &ft_strlen_empty_test);

    int result = launch_tests(&tests, "ft_strlen");

    clear_tests(&tests);
    return result;
}
