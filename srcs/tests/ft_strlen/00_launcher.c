#include "../../../includes/libunit.h"

int ft_strlen_launcher(void)
{
    t_test *tests = NULL;

    load_test(&tests, "Basic test", &basic_test);
    load_test(&tests, "Empty test", &empty_test);

    int result = launch_tests(&tests);

    clear_tests(&tests);
    return result;
}
